cmake_minimum_required(VERSION 3.0.2)
project(d_load_plugin)
include(CMakePrintHelpers)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  a_simple_plugin_example
  pluginlib
)

catkin_package(
  CATKIN_DEPENDS roscpp a_simple_plugin_example pluginlib
)
cmake_print_variables(${catkin_LIBRARIES})


include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/d_load_plugin_node.cpp)

target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
)










