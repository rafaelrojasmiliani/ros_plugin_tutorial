#include <c_create_plugin/plugin_rectangle.h>
#include <pluginlib/class_list_macros.h>
namespace rectangle {
cPluginRectangle::cPluginRectangle():regular_polygon::cRegularPolygon() {}

cPluginRectangle::cPluginRectangle(const cPluginRectangle &that) {}

cPluginRectangle::~cPluginRectangle() {}

cPluginRectangle &cPluginRectangle::operator=(const cPluginRectangle &that) {
  regular_polygon::cRegularPolygon::operator=(that);
  return *this;
}

void cPluginRectangle::initialize(const double &x, const double &y, const double &r) {
    *x_ = x;
    *y_ = y;
    *radius_ = r;
    *area_ = 0.1;

}
} // namespace rectangle
PLUGINLIB_EXPORT_CLASS(rectangle::cPluginRectangle,
                       regular_polygon::cRegularPolygon)
