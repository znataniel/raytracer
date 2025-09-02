#ifndef HITTABLES_LIST_H
#define HITTABLES_LIST_H

#include "hittables.h"
#include "utils.h"
#include <vector>

using std::shared_ptr;

class HittableList : public Hittable {
private:
  std::vector<shared_ptr<Hittable>> objects{};

public:
  HittableList() {}
  HittableList(shared_ptr<Hittable> object) { add(object); }
  void add(shared_ptr<Hittable> object) { objects.push_back(object); }
  void clear() { objects.clear(); }

  // ray_tmax is the farthest the ray can go, it starts there. While we
  // traverse the ray to find hit objects, we start updating that limit to
  // stop going farther away than the closest thing we hit
  bool hit(const Ray &r, Interval ray_t, hit_record &rec) const override {
    double closest_t_so_far = ray_t.max;
    bool did_hit = false;
    hit_record aux_record{};

    for (const auto &o : objects) {
      if (o->hit(r, Interval(ray_t.min, closest_t_so_far), aux_record)) {
        did_hit = true;
        closest_t_so_far = aux_record.t;
      }
    }

    rec = aux_record;
    return did_hit;
  }
};

#endif