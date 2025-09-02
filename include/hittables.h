#ifndef HITTABLES_H
#define HITTABLES_H

#include "utils.h"

struct hit_record {
  Point p;
  Vector normal;
  double t;
  bool front_face;
  void set_front_face(const Ray &r, Vector &outwards_normal) {
    front_face = r.direction().dot(outwards_normal) < 0;
    normal = front_face? outwards_normal : -outwards_normal;
  }
};

class Hittable {
public:
  virtual ~Hittable() = default;

  // the ray that hits the object, the valid interval that we are evaluating,
  // and the hit record with the hit info (normal, the point where it hit, and
  // how much the ray had traversed)
  virtual bool hit(const Ray &r, double ray_tmin, double ray_tmax,
                   hit_record &rec) const = 0;
};

#endif