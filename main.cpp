#include "include/cameras.h"
#include "include/hittables.h"
#include "include/hittables_list.h"
#include "include/spheres.h"
#include "include/utils.h"

#include <algorithm>
#include <fstream>

int main(void) {
  std::ofstream outfile("build/out.ppm", std::ios::binary);

  HittableList world;
  world.add(make_shared<Sphere>(Point(0, 0, -1), 0.5));
  world.add(make_shared<Sphere>(Point(0, -100.5, -1), 100));

  Camera camera{};
  camera.aspect_ratio = 16.0 / 9.0;
  camera.im_width = 400;

  camera.render(outfile, world);

  outfile.close();
  return EXIT_SUCCESS;
}