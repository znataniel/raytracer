#include "include/colors.h"
#include "include/vectors.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

#define WIDTH 256
#define HEIGHT 256

int main(void) {
  std::ofstream outfile("./build/out.ppm", std::ios::binary);

  // header
  outfile << "P3"
          << " " << WIDTH << " " << HEIGHT << " "
          << "255"
          << "\n";

  for (int j = 0; j < HEIGHT; j++) {
    std::clog << "\rScanlines remaining: " << HEIGHT - j << " " << std::flush;
    for (int i = 0; i < WIDTH; i++) {
      double u = double(i) / (WIDTH - 1);
      double v = double(j) / (HEIGHT - 1);
      write_color(outfile, Color(u, v, 0.0));
    }
  }

  outfile.close();
  std::cout << "\rDone.                                      " << std::endl;
  return EXIT_SUCCESS;
}