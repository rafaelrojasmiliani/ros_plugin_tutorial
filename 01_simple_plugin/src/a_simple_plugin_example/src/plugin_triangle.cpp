#include <a_simple_plugin_example/plugin_triangle.h>
#include <math.h>
#include <pluginlib/class_list_macros.h>
#include <stdlib.h>
namespace triangle {

cPluginTriangle::cPluginTriangle() : regular_polygon::cRegularPolygon() {
  dummy_var_ = new double(0);
}

cPluginTriangle::~cPluginTriangle() { delete dummy_var_; }

cPluginTriangle::cPluginTriangle(const cPluginTriangle &that)
    : regular_polygon::cRegularPolygon(that) {
  dummy_var_ = new double(0);
}

cPluginTriangle &cPluginTriangle::operator=(const cPluginTriangle &that) {
  regular_polygon::cRegularPolygon::operator=(that);
  *dummy_var_ = *that.dummy_var_;
  return *this;
}

double cPluginTriangle::get_area() {
  const double r = *radius_;
  const double A = r * r * sin(2.0 * 3.1415 / 3.0);
  return A;
}

void cPluginTriangle::dummy_function(int _A) {
  double a = get_area();
  a = _A;
  void *m = (void *)malloc(1);

  free(m);
}

void cPluginTriangle::initialize(const double &_x, const double &_y,
                                  const double &_r) {
  *x_ = _x;
  *y_ = _y;
  *radius_ = _r;
}
} // namespace triangle
PLUGINLIB_EXPORT_CLASS(triangle::cPluginTriangle,
                       regular_polygon::cRegularPolygon)
