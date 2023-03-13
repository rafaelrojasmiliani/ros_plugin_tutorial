
# ROS Plugin Tutorial

Tutorial to program ROS plugins

## Concepts

- **Shared library** is a binary file that is intended to be shared by executable files and further shared libraries.
The resources available in shared libraries can be loaded into the program's memory space at load time or runtime, rather than only at compiling time as **Static Libraries**.

- **Plugin** is an instance of a class that can be loaded at runtime inside a program which were not linked against the library where the plugin was compiled. This kind of instances have minimal restrictions

- **Plugin base class** or **interface plugin** is the class from which a given Plugin derives.


**NOTE** It is currently not possible to pass constructor arguments to plugins loaded by pluginlib [see here](https://github.com/ros/pluginlib/issues/127#issuecomment-421419008). At most, `pluginlib` uses the default constructor with the default arguments.

## What is a Plugin and what does `pluginlib` do`?

A **Plugin** is an instance of a class that can be loaded at runtime inside a program which were not linked against the library where the plugin was compiled.
A Plugin class is always derived from a base class that has been defined (and linked if implemented) into the program at compilation time.
We call the base class of a Plugin the **Plugin base class** or **interface plugin**.
`pluginlib` is a C++ library for loading and unloading plugins from within a ROS package.
With `pluginlib`, one does not have to explicitly link their application against the library containing the implementation of a Plugin class.
The unique requirement is that the program needs the definition (and minimal implementation if necessary) of the Plugin base class from which the desired Plugin derives.

In other words, `pluginlib` opens a library containing the compiled implementation of the Plugin at runtime without the need of having any prior awareness Plugin implementation or definition provided the program has been compiled and linked with the Plugin base definition and implementation.
Plugins are useful for extending/modifying application behavior without needing the application source code.

The `pluginlib` ROS package is a high level wrapper of the `class_loader` ROS package.
The `pluginlib` is in this [repo](git@github.com:rafaelrojasmiliani/ros_plugin_tutorial.git).

## Restriction of Plugins classes

- Must have a constructor with no arguments (or default arguments). In order to implment a custom initialization an "`initialize`" function must be implemented.

## The `class_loader` Package

The `class_loader` package has its main site [here](http://wiki.ros.org/class_loader) and its [source code here](https://github.com/ros/class_loader) `class_loader` is a ROS-independent package that allows one to dynamically load instances of C++ classes at runtime from a shared library.

Thanks to `class_loader` your code does not require the definition not the implementation of the class.
Classes loaded in this fashion are also often called plugins.

At its core `class_loader` is just an implementation of the POCO shared library tool.

## The POCO shared library class

The [POCO C++ libraries](https://pocoproject.org) are a collection of open source C++ class libraries that simplify and accelerate the development of network-centric, portable applications in C++.

For loading (and unloading) shared libraries at runtime, POCO has a low-level `Poco::SharedLibrary` class.
Based on it is the `Poco::ClassLoader` class template and supporting framework, allowing dynamic loading and unloading of C++ classes at runtime.

The `Poco::SharedLibrary` is [defined here](https://github.com/austinsc/Poco/blob/f459e1ddb12354edd5c9908b2d53ec129bdcfa98/Foundation/include/Poco/SharedLibrary.h#L64) and [implemented here](https://github.com/austinsc/Poco/blob/master/Foundation/src/SharedLibrary.cpp).
It derives from `Poco::SharedLibraryImpl` which implementation depends on the operative system.
For UNIX system is [defined here](https://github.com/austinsc/Poco/blob/f459e1ddb12354edd5c9908b2d53ec129bdcfa98/Foundation/include/Poco/SharedLibrary_UNIX.h#L50) and [implemented here](https://github.com/austinsc/Poco/blob/master/Foundation/src/SharedLibrary_UNIX.cpp).

In the UNIX implementation, `Poco::SharedLibrary` is a wrapper for the POSIX `dlopen` function.

In the Windows implementation, `Poco::SharedLibrary` is a wrapper for `LoadLibraryExA` [documented here](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa) for ANSI or `LoadLibraryExW` [documented here](https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) for UNICODE.

## The POSIX `dlopen`,  ``dlclose` ``dlerror`and `dlsym` functions

The four functions `dlopen`, `ldsym`, `dlclose`, `dlerror` implement the interface to the dynamic linking loader.
These function are defined in `dlfcn.h` and require compilation flags as
```
gcc -rdynamic -o foo foo.c -ldl
```

- **`dlerror`** returns a human readable string describing the most recent error that occurred from `dlopen`, `ldsym` or `dlclose` since the last call to `dlerror`.
It returns NULL if no errors have occurred since initialization or since it was last called.

- **`dlopen`** The function `dlopen` loads the dynamic library file named by the null-terminated string filename and returns an opaque "handle" for the dynamic library.
If filename is NULL, then the returned handle is for the main program.
If filename contains a slash ("/"), then it is interpreted as a (relative or absolute) pathname.
Otherwise, the dynamic linker searches for the library as follows (see ld.so(8) for further details):
    - If defined, search on `DT_RPATH`, `DT_RUNPATH`. `DT_RUNPATH` has priority.

    - If defined search on `LD_LIBRARY_PATH`.
    - The cache file `/etc/ld.so.cache` (maintained by `ldconfig` (man 8)) is checked to see whether it contains an entry for filename.
    - The directories `/lib` and `/usr/lib` are searched (in that order).
If the library has dependencies on other shared libraries, then these are also automatically loaded by the dynamic linker using the same rules.
(This process may occur recursively, if those libraries in turn have dependencies, and so on.)
If the executable was linked with the flag `-rdynamic` (or, synonymously, `--export-dynamic`), then the global symbols in the executable will also be used to resolve references in a dynamically loaded library.
If `dlopen` fails for any reason, it returns NULL.

- **`ldsym`**  takes a "handle" of a dynamic library returned by `dlopen` and the null-terminated symbol name, returning the address where that symbol is loaded into memory.
If the symbol is not found returns NULL.

- **`dlclose`** The function `dlclose` decrements the reference count on the dynamic library handle handle.
If the reference count drops to zero and no other loaded libraries use symbols in it, then the dynamic library is unloaded.
Returns 0 on success, and nonzero on error.


# Detailed description of how a plugin is loaded:

1. We create a class loader instance of [`pluginlib::ClassLoader<typename BasePluginType>`](https://github.com/ros/pluginlib/blob/5fb0f10d2d354aad5d245c806d61dfa8d3863e64/pluginlib/include/pluginlib/class_loader.hpp#L61). This class is a wrapper if `  class_loader::MultiLibraryClassLoader lowlevel_class_loader_;  // The underlying classloader`  [declared here](https://github.com/ros/class_loader/blob/b1954d413aac64cfd65ba8cf2768da62455cb4cd/include/class_loader/multi_library_class_loader.hpp#L56).
2. Call [`pluginlib::ClassLoader<typename BasePluginType>::createUniqueInstance`](https://github.com/ros/pluginlib/blob/5fb0f10d2d354aad5d245c806d61dfa8d3863e64/pluginlib/include/pluginlib/class_loader_imp.hpp#L169)
    1. Here we check if the library is already loaded [`pluginlib::ClassLoader<typename BasePluginType>::isClassLoaded(const std::string & lookup_name)`](https://github.com/ros/pluginlib/blob/5fb0f10d2d354aad5d245c806d61dfa8d3863e64/pluginlib/include/pluginlib/class_loader_imp.hpp#L380). This only calls [`class_loader::MultiLibraryClassLoader::isClassAvailable`](https://github.com/ros/class_loader/blob/b1954d413aac64cfd65ba8cf2768da62455cb4cd/include/class_loader/multi_library_class_loader.hpp#L245)
    2. Then we call [`class_loader::MultiLibraryClassLoader::getAvailableClasses`](https://github.com/ros/class_loader/blob/b1954d413aac64cfd65ba8cf2768da62455cb4cd/include/class_loader/multi_library_class_loader.hpp#L265)
    3. This calls [`class_loader::MultiLibraryClassLoader::getAllAvailableClassLoaders`](https://github.com/ros/class_loader/blob/b1954d413aac64cfd65ba8cf2768da62455cb4cd/src/multi_library_class_loader.cpp#L68)
3. call [`MultiLibraryClassLoader::loadLibrary(`](https://github.com/ros/class_loader/blob/b1954d413aac64cfd65ba8cf2768da62455cb4cd/src/multi_library_class_loader.cpp#L82)
