#include <a_simple_plugin_example/plugin_base_class.h>
#ifndef PLUGIN_RECTANGLE_H
#define PLUGIN_RECTANGLE_H
namespace rectangle {
class cPluginRectangle:public regular_polygon::cRegularPolygon {
private:
public:
  cPluginRectangle();
  cPluginRectangle(const cPluginRectangle &that);
  cPluginRectangle &operator=(const cPluginRectangle &);
  virtual ~cPluginRectangle();
  void initialize(const double &x, const double &y,
                          const double &r);
};
} // namespace rectangle
#endif /* PLUGIN_RECTAMGLE_H */
