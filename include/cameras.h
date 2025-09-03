#ifndef CAMERAS_H
#define CAMERAS_H

#include "hittables_list.h"
#include "utils.h"
#include <fstream>

class Camera {
private:
  int im_height;
  Point center;
  Point vp_pixel_00;
  Vector d_pixel_u;
  Vector d_pixel_v;

  void initialize() {
    im_height = int(im_width / aspect_ratio);
    im_height = im_height < 1 ? 1 : im_height;
    const double vp_height = 2.0;
    const double vp_width = vp_height * (double(im_width) / im_height);

    const double focal_length = 1.0;
    center = Vector(0, 0, 0);

    const Vector vp_vector_u = Vector(vp_width, 0, 0);
    const Vector vp_vector_v = Vector(0, -vp_height, 0);
    d_pixel_u = vp_vector_u / im_width;
    d_pixel_v = vp_vector_v / im_height;

    const Point vp_upper_left_corner =
        center - Vector(0, 0, focal_length) - vp_vector_u / 2 - vp_vector_v / 2;
    vp_pixel_00 = vp_upper_left_corner + d_pixel_u / 2 + d_pixel_v / 2;
  }

  Color ray_color(const Ray &r, const HittableList &world) {

    hit_record h_rec{};

    if (world.hit(r, Interval(0, infinity), h_rec)) {
      return Color(h_rec.normal.X() + 1, h_rec.normal.Y() + 1,
                   h_rec.normal.Z() + 1) /
             2;
    }

    const Vector normalized = r.direction().norm();
    const double a = (normalized.Y() + 1) / 2;
    const Color lerp = (1 - a) * Color(1, 1, 1) + a * Color(0.5, 0.7, 1.0);
    return lerp;
  }

public:
  double aspect_ratio = 1.0;
  double im_width = 100;

  void render(std::ofstream &outfile, const HittableList &world) {
    initialize();

    outfile << "P3"
            << " " << im_width << " " << im_height << " "
            << "255"
            << "\n";

    for (int j = 0; j < im_height; j++) {
      std::clog << "\rScanlines remaining: " << im_height - j << " "
                << std::flush;
      for (int i = 0; i < im_width; i++) {
        const Point pixel = vp_pixel_00 + d_pixel_u * i + d_pixel_v * j;
        const Vector ray_dir = pixel - center;
        const Ray ray{center, ray_dir};
        const Color color = ray_color(ray, world);

        write_color(outfile, color);
      }
    }
    std::clog << "\rDone.                                      " << std::endl;
  }
};

#endif