#ifndef VECTORS_H
#define VECTORS_H

#include <cmath>
#include <iostream>
#include <ostream>

class Vector {
private:
  double x;
  double y;
  double z;

public:
  Vector();
  Vector(double, double, double);
  Vector(const Vector &);
  Vector &operator+=(const Vector &);
  Vector &operator-=(const Vector &);
  Vector &operator*=(double);
  Vector &operator/=(double);
  Vector &operator-();
  double dot(const Vector &) const;
  Vector cross(const Vector &) const;
  double length() const;
  Vector norm() const;
  Vector operator!();
  double X() const;
  double Y() const;
  double Z() const;
};

Vector operator+(const Vector &, const Vector &);
Vector operator-(const Vector &, const Vector &);
Vector operator*(const Vector &, double);
Vector operator*(double, const Vector &);
Vector operator/(const Vector &, double);

std::ostream& operator<<(std::ostream, const Vector&);

using Point = Vector;

#endif