#include "vectors.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

#define WIDTH 256
#define HEIGHT 256

int main(void) {
  std::ofstream outfile("out.ppm", std::ios::binary);

  outfile << "P3" << " " << WIDTH << " " << HEIGHT << " " << "255" << "\n";
  for (int j = 0; j < HEIGHT; j++) {
    std::clog << "\rScanlines remaining: " << HEIGHT - j << " " << std::flush;
    for (int i = 0; i < WIDTH; i++) {
      double u = double(i) / (WIDTH - 1);
      double v = double(j) / (HEIGHT - 1);

      int ir = int(255.999 * u);
      int ig = int(255.999 * v);
      int ib = int(255.999 * 0.0);

      outfile << ir << " " << ig << " " << ib << '\n';
    }
  }

  outfile.close();
  std::cout << "\rDone.                                      " << std::endl;
  return EXIT_SUCCESS;
}