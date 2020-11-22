
| package | description |
| ------- | ----------- |
| `a_simple_plugin_example` | describes how to create a simple plugin base and a plugin and make it available to other packages |
| `b_load_plugin` | describes how to load a plugin |

# How to create a simple plugin?


1. Create or identify the base class for the pluging
2. Write the definition (header) and the implementation (`.cpp`) of the pluging as a class which derives from the plugin class.
3. Make the plugin available to the catkin system
    1. Register at code level
    2. Register at package level
    3. At CMake level
