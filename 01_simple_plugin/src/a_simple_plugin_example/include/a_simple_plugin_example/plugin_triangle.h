#ifndef PLUGING_TRIANGLE_H
#define PLUGING_TRIANGLE_H

#include <a_simple_plugin_example/plugin_base_class.h>
namespace triangle {
class cPlugingTriangle : regular_polygon::cRegularPolygon {
private:
public:
  cPlugingTriangle();
  cPlugingTriangle(const cPlugingTriangle &that);
  cPlugingTriangle &operator=(const cPlugingTriangle &that);
  virtual ~cPlugingTriangle();

  void initialize(const double &_x, const double &_y, const double &_r);
  double get_area();
  void dummy_function(int _A);
  double *dummy_var_;
};
} // namespace triangle
#endif /* PLUGING_TRIANGLE_H */
