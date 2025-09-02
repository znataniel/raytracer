#ifndef SPHERES_H
#define SPHERES_H

#include "hittables.h"
#include "utils.h"

class Sphere : public Hittable {
private:
  Point center;
  double radius;

public:
  Sphere(const Point &center, double radius)
      : center(center), radius(std::fmax(0, radius)) {}

  bool hit(const Ray &r, double ray_tmin, double ray_tmax,
           hit_record &rec) const override {

    const Vector d = r.direction();
    const Vector q = center - r.origin();
    const double a = d.length() * d.length();
    const double h = d.dot(q);
    const double c = q.length() * q.length() - radius * radius;
    const double disc = h * h - a * c;

    if (disc < 0) {
      return false;
    }

    const double sqrt_disc = std::sqrt(disc);

    // root 1
    double t = (h - sqrt_disc) / a;
    if (t < ray_tmin || ray_tmax < t) {
      // root 2
      t = (h + sqrt_disc) / a;
      if (t < ray_tmin || ray_tmax < t) {
        return false;
      }
    }

    rec.t = t;
    rec.p = r.at(rec.t);

    Vector normal = (rec.p - center) / radius;
    rec.set_front_face(r, normal);

    return true;
  }
};

#endif