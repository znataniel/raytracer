#ifndef RAYS_H
#define RAYS_H

#include "vectors.h"

class Ray {
private:
  Point orig;
  Vector dir;

public:
  Ray() {}
  Ray(const Point &origin, const Vector &direction) {
    orig = origin;
    dir = direction;
  }

  const Point &origin() const { return orig; }
  const Vector &direction() const { return dir; }

  Point at(double t) const { return orig + dir * t; }
};

#endif