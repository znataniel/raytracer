#ifndef COLORS_H
#define COLORS_H

#include "vectors.h"
#include <fstream>

using Color = Vector;

inline void write_color(std::ofstream &out, const Color &pixel_color) {
  double r = pixel_color.X();
  double g = pixel_color.Y();
  double b = pixel_color.Z();

  int rb = int(255.999 * r);
  int gb = int(255.999 * g);
  int bb = int(255.999 * b);

  out << rb << " " << gb << " " << bb << "\n";
}

#endif