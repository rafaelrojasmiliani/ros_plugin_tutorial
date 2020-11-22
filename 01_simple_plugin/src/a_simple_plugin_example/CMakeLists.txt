cmake_minimum_required(VERSION 3.0.2)
project(a_simple_plugin_example)
find_package(catkin REQUIRED COMPONENTS pluginlib roscpp)

catkin_package(INCLUDE_DIRS include LIBRARIES plugin_triangle polygons)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(plugin_triangle src/plugin_triangle.cpp)

add_library(polygons src/plugin_base_class.cpp)
# add_executable(${PROJECT_NAME}_node src/a_simple_plugin_example_node.cpp)
# target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES} )
