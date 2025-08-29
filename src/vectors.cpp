#include "../include/vectors.h"

Vector::Vector() {
  x = 0;
  y = 0;
  z = 0;
}

Vector::Vector(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector::Vector(const Vector &rhs) {
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
}

Vector &Vector::operator+=(const Vector &rhs) {
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;
  return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;
  return *this;
}

Vector &Vector::operator*=(double k) {
  x *= k;
  y *= k;
  z *= z;
  return *this;
}

Vector &Vector::operator/=(double k) {
  x /= k;
  y /= k;
  z /= z;
  return *this;
}

Vector &Vector::operator-() {
  x = -x;
  y = -y;
  z = -z;
  return *this;
}

double Vector::dot(const Vector &rhs) const {
  return (x * rhs.x + y * rhs.y + z * rhs.z);
}

Vector Vector::cross(const Vector &rhs) const {
  return Vector(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
                x * rhs.y - y * rhs.x);
}

double Vector::length() const { return sqrt(x * x + y * y + z * z); }

Vector Vector::norm() const {
  double len = this->length();
  return Vector{x / len, y / len, z / len};
}

Vector Vector::operator!() { return this->norm(); }

double Vector::X() const { return x; }
double Vector::Y() const { return y; }
double Vector::Z() const { return z; }

Vector operator+(const Vector &lhs, const Vector &rhs) {
  return Vector{lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z()};
}

Vector operator-(const Vector &lhs, const Vector &rhs) {
  return Vector{lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z()};
}

Vector operator*(const Vector &lhs, double k) {
  return Vector(lhs.X() * k, lhs.Y() * k, lhs.Z() * k);
}

Vector operator*(double k, const Vector &rhs) { return rhs * k; }
Vector operator/(const Vector &lhs, double k) { return (1 / k) * lhs; }

std::ostream &operator<<(std::ostream out, const Vector &rhs) {
  return out << rhs.X() << " " << rhs.Y() << " " << rhs.Z();
}