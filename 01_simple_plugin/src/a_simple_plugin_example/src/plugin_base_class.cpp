#include <a_simple_plugin_example/plugin_base_class.h>
namespace regular_polygon {
cRegularPolygon::cRegularPolygon() {
  area_ = new double(0);
  x_ = new double(0);
  y_ = new double(0);
}
cRegularPolygon::~cRegularPolygon() {
  delete area_;
  delete x_;
  delete y_;
}
cRegularPolygon::cRegularPolygon(const cRegularPolygon &that) {
  area_ = new double(0);
  x_ = new double(0);
  y_ = new double(0);
  *area_ = *that.area_;
  *x_ = *that.x_;
  *y_ = *that.y_;
}

cRegularPolygon &cRegularPolygon::operator=(const cRegularPolygon &that) {
  *area_ = *that.area_;
  *x_ = *that.x_;
  *y_ = *that.y_;
  return *this;
}

double cRegularPolygon::get_area() { return *area_; }

double cRegularPolygon::get_radius() { return *radius_; }

void cRegularPolygon::get_position(double &x, double &y) {
  x = *x_;
  y = *y_;
}
} // namespace regular_polygon
