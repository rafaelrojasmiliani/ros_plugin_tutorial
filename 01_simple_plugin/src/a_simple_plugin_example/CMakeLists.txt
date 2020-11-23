cmake_minimum_required(VERSION 3.0.2)
project(a_simple_plugin_example)
find_package(catkin REQUIRED COMPONENTS pluginlib roscpp)

# this arguments are REQUIRED to use this resoureces in other packages
catkin_package(INCLUDE_DIRS include LIBRARIES plugin_triangle polygons)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(plugin_triangle src/plugin_triangle.cpp)

add_library(polygons src/plugin_base_class.cpp)
