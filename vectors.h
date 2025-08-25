#ifndef VECTORS_H
#define VECTORS_H

#include <cmath>
#include <iostream>

class Vector {
private:
  double x;
  double y;
  double z;

public:
  Vector(double x = 0, double y = 0, double z = 0);
  Vector operator+(const Vector &other);
  Vector operator-(const Vector &other);
  double dot(const Vector &other);
  double norm();
  void display() const;
};

#endif