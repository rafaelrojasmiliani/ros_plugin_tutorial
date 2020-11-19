#include <a_simple_plugin_example/plugin_triangle.h>
#include <math.h>
#include <stdlib.h>
namespace triangle {

cPlugingTriangle::cPlugingTriangle() : regular_polygon::cRegularPolygon() {
  dummy_var_ = new double(0);
}

cPlugingTriangle::~cPlugingTriangle() { delete dummy_var_; }

cPlugingTriangle::cPlugingTriangle(const cPlugingTriangle &that)
    : regular_polygon::cRegularPolygon(that) {
  dummy_var_ = new double(0);
}

cPlugingTriangle &cPlugingTriangle::operator=(const cPlugingTriangle &that) {
  regular_polygon::cRegularPolygon::operator=(that);
  *dummy_var_ = *that.dummy_var_;
  return *this;
}

double cPlugingTriangle::get_area() {
  const double r = *radius_;
  const double A = r * r * sin(2.0 * 3.1415 / 3.0);
  return A;
}

void cPlugingTriangle::dummy_function(int _A) {
  double a = get_area();
  a = _A;
  void *m = (void *)malloc(1);

  free(m);
}

void cPlugingTriangle::initialize(const double &_x, const double &_y,
                                  const double &_r) {
  *x_ = _x;
  *y_ = _y;
  *radius_ = _r;
}
} // namespace triangle
