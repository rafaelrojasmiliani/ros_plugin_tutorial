
This example shows how to use ROS plugins to implemented different types of regular polygons.
The **Plugin base class** is defined in `include/a_simple_plugin_example/plugin_base_class.h`.

Each polygon will be able to 

- store its position
- store its radius
- compute its own area, this will be custom for each polygon

Because `pluginlib` does not allow to have custom constructors, we will need to add a custom initialization function.

In order to make a more appealing example, our Plugin base class will handle memory allocation.

## Creating the Plugin base class also called interface plugin 
In our case we have an abstract class which only implements the common features of all polygons: get the position and the radius.
The pure virtual method of the base class is the method that will be implemented using Plugins.
A plugin base class does not requires any kind of reference to `pluginlib`.

- We require a namespace
- Constructor without arguments
