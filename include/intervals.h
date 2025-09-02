#ifndef INTERVALS_H
#define INTERVALS_H

#include <limits>
const double infinity = std::numeric_limits<double>::infinity();

class Interval {
public:
  double min, max;
  Interval() { min = infinity, max = -infinity; } // empty interval
  Interval(double min, double max) : min(min), max(max) {}

  double size() const { return max - min; }
  bool contains(double x) const { return min <= x && x <= max; }
  bool surrounds(double x) const { return min < x && x < max; }

  static const Interval empty, universe;
};

const Interval Interval::empty = Interval(infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, infinity);

#endif