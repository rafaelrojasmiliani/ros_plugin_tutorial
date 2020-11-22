cmake_minimum_required(VERSION 3.0.2)
include(CMakePrintHelpers)
project(b_load_plugin)
find_package(catkin REQUIRED COMPONENTS a_simple_plugin_example pluginlib
                                        roscpp)
catkin_package(CATKIN_DEPENDS roscpp a_simple_plugin_example pluginlib)
include_directories(${catkin_INCLUDE_DIRS})
add_executable(${PROJECT_NAME}_node src/b_load_plugin_node.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
