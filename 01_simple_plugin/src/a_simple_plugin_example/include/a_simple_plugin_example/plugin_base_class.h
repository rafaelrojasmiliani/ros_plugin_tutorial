#ifndef PLUGIN_BASE_CLASS_H
#define PLUGIN_BASE_CLASS_H

namespace regular_polygon {
class cRegularPolygon {
public:
  cRegularPolygon();
  cRegularPolygon(const cRegularPolygon &that);
  cRegularPolygon &operator=(const cRegularPolygon &that);
  virtual void initialize(const double &x, const double &y,
                          const double &r) = 0;
  virtual double get_area();
  double get_radius();
  void get_position(double &x, double &y);
  virtual ~cRegularPolygon();
  double *area_;
  double *x_;
  double *y_;
  double *radius_;
};
} // namespace regular_polygon
#endif /* PLUGIN_BASE_CLASS_H */
