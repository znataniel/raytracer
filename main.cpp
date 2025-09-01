#include "include/colors.h"
#include "include/rays.h"
#include "include/vectors.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

double hit_sphere(const Point &sph_center, const double r, const Ray &ray) {
  const Vector d = ray.direction();
  const Vector q = sph_center - ray.origin();
  const double a = d.length() * d.length();
  const double h = d.dot(q);
  const double c = q.length() * q.length() - r * r;
  const double disc = h * h - a * c;
  return (disc < 0) ? -1.0 : (h - std::sqrt(disc)) / a;
}

const Color ray_color(const Ray &r) {
  const double t = (hit_sphere(Point(-0.2, 0.2, -1.0), 0.5, r));
  if (t > 0) {
    const Vector normal = r.at(t) - Vector(-0.2, 0.2, -1.0);
    return Color(normal.X() + 1, normal.Y() + 1, normal.Z() + 1) / 2;
  }
  const Vector normalized = r.direction().norm();
  const double a = (normalized.Y() + 1) / 2;
  const Color lerp = (1 - a) * Color(1, 1, 1) + a * Color(0.00000001, 1.0, 0.00000001);
  return lerp;
}

int main(void) {
  std::ofstream outfile("build/out.ppm", std::ios::binary);

  const double aspect_ratio = 16.0 / 9.0;
  const int im_width = 400;
  const int im_height = std::max(1, int(im_width / aspect_ratio));

  const double vp_height = 2;
  const double vp_width = vp_height * (double(im_width) / im_height);

  const double focal_length = 1.0;
  const Vector camera = Vector(0, 0, 0);

  const Vector vp_vector_u = Vector(vp_width, 0, 0);
  const Vector vp_vector_v = Vector(0, -vp_height, 0);
  const Vector d_pixel_u = vp_vector_u / im_width;
  const Vector d_pixel_v = vp_vector_v / im_height;

  const Point vp_upper_left_corner =
      camera - Vector(0, 0, focal_length) - vp_vector_u / 2 - vp_vector_v / 2;
  const Point vp_pixel_00 =
      vp_upper_left_corner + d_pixel_u / 2 + d_pixel_v / 2;

  // ppm header
  outfile << "P3"
          << " " << im_width << " " << im_height << " "
          << "255"
          << "\n";

  for (int j = 0; j < im_height; j++) {
    std::clog << "\rScanlines remaining: " << im_height - j << " "
              << std::flush;
    for (int i = 0; i < im_width; i++) {
      const Point pixel = vp_pixel_00 + d_pixel_u * i + d_pixel_v * j;
      const Vector ray_dir = pixel - camera;
      const Ray ray{camera, ray_dir};
      const Color color = ray_color(ray);

      write_color(outfile, color);
    }
  }

  outfile.close();
  std::cout << "\rDone.                                      " << std::endl;
  return EXIT_SUCCESS;
}