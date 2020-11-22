#ifndef PLUGING_TRIANGLE_H
#define PLUGING_TRIANGLE_H

#include <a_simple_plugin_example/plugin_base_class.h>
namespace triangle {
class cPluginTriangle : public regular_polygon::cRegularPolygon {
private:
public:
  cPluginTriangle();
  cPluginTriangle(const cPluginTriangle &that);
  cPluginTriangle &operator=(const cPluginTriangle &that);
  virtual ~cPluginTriangle();

  void initialize(const double &_x, const double &_y, const double &_r);
  double get_area();
  void dummy_function(int _A);
  double *dummy_var_;
};
} // namespace triangle
#endif /* PLUGING_TRIANGLE_H */
