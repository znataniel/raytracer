#include "vectors.h"

using std::cout;
using std::endl;

Vector::Vector(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector Vector::operator+(const Vector &other) {
  return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector &other) {
  return Vector(x - other.x, y - other.y, z - other.z);
}

double Vector::dot(const Vector &other) {
  return (x * other.x + y * other.y + z * other.z);
}

double Vector::norm() { return sqrt(x * x + y * y + z * z); }

void Vector::display() const {
  cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}