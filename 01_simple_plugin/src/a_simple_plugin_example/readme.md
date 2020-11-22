
This example shows how to use ROS plugins to implemented different types of regular polygons.
The **Plugin base class** is defined in `include/a_simple_plugin_example/plugin_base_class.h`.

Each polygon will be able to 

- store its position
- store its radius
- compute its own area, this will be custom for each polygon

Because `pluginlib` does not allow to have custom constructors, we will need to add a custom initialization function.

In order to make a more appealing example, our Plugin base class will handle memory allocation.

## Creating the Plugin base class also called interface plugin 

### Plugin declaration (header)
In our case we have an abstract class which only implements the common features of all polygons: get the position and the radius.
The pure virtual method of the base class is the method that will be implemented using Plugins.
A plugin base class does not requires any kind of reference to `pluginlib`.

- We require a namespace
- Constructor without arguments

# Expose the plugins to the Catkin toolchain


# How did we create this package
```
catkin create pkg PACKAGE_NAME roscpp pluginlib
```

It installs the `package.xml` file, and it generates code for `find_package` and `pkg-config` so that other packages can get information about this package.

### `catkin_package` arguments
- `INCLUDE_DIRS`: relative paths to C/C++ includes
- `LIBRARIES`: names of library targets that will appear in the `catkin_LIBRARIES` and `${PROJECT_NAME}_LIBRARIES` of other projects that search for you via `find_package`.
 Currently this will break if the logical target names are not the same as the installed names.

- `CATKIN_DEPENDS`: a list of catkin projects which this project depends on.

- `DEPENDS`: a list of CMake projects which this project depends on.

