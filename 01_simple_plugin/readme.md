
| package | description |
| ------- | ----------- |
| `a_simple_plugin_example` | describes how to create a simple plugin base and a plugin and make it available to other packages |
| `b_load_plugin` | describes how to load a plugin created in another package |
| `c_plugin_another_package` | describes how to create a plugin such that its base plugin was created in another package |
| `d_load_plugin` | describes how to load a plugin which base is in `packageA` but is defined in `packageB`  |





# Example 1: `a_simple_plugin_example`
In this example we learn how to create a plugin with a custom plugin base.

1. Create the plugin base. This steps does not strictly depends on any ROS component and consist in creating a C++ class indented to be used with inheritance.
2. Create the plugin. The unique requirement from ROS functionality strictly required is call to the `pluginglib` macro
```
PLUGINLIB_EXPORT_CLASS
```
3. Make the plugin available to the catkin system
    1. Register at code level with (`PLUGINLIB_EXPORT_CLASS` in point 2.)
    2. Register at package level (with the `export` tag in `package.xml` and creating the `plugin.xml`)
    3. At CMake level (making available the libraries and header to the system with
    ```
    catkin_package(INCLUDE_DIRS include LIBRARIES <libs>)
    ```

# Example 2: `b_load_plugin`
In this example we learn how to load a plugin

# Example 3: `c_create_plugin`
In this example we create a new plugin for the plugins with base class defined in `a_simple_plugin_example`.
This is the procedure that we need to create ROS control and ROS MoveIt plugins.

# Example 4: `d_load_plugin`
In this example we load the plugin created in `c_create_plugin`
