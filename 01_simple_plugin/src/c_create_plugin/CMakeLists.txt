cmake_minimum_required(VERSION 3.0.2)
project(c_create_plugin)
find_package(catkin REQUIRED COMPONENTS
  a_simple_plugin_example
  pluginlib
  roscpp
)
# this arguments are REQUIRED to use this resoureces in other packages
catkin_package(INCLUDE_DIRS include LIBRARIES plugin_triangle polygons CATKIN_DEPENDS a_simple_plugin_example)
cmake_print_variables(${catkin_INCLUDE_DIRS})
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)
add_library(plugin_rectangle
   src/plugin_rectangle.cpp  
)
