#include <a_simple_plugin_example/plugin_base_class.h>
#include <pluginlib/class_loader.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  // Set up ROS.
  ros::init(argc, argv, "b_load_plugin_node");
  ros::NodeHandle nh;

  // need to #include <pluginlib/class_loader.h> and plusing header
  pluginlib::ClassLoader<regular_polygon::cRegularPolygon> poly_loader(
      "a_simple_plugin_example", "regular_polygon::cRegularPolygon");

  try {
    boost::shared_ptr<regular_polygon::cRegularPolygon> plugin_instance =
        poly_loader.createInstance("triangle::cPluginTriangle");

    plugin_instance->initialize(1, 2, 3);
  } catch (pluginlib::PluginlibException &ex) {
    ROS_ERROR("The plugin failed to load  . Error: %s at file %s line %d",
              ex.what(), __FILE__, __LINE__);
  }
  ros::shutdown();
  return 0;
}
