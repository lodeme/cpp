#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}

Point::Point(const Point& other) {
  *this = other;
}

Point& Point::operator=(const Point& other) {
  if (this != &other) {
    this->_x = other._x;
    this->_y = other._y;
  }
  return *this;
}

Point::~Point(void) {}

const Fixed& Point::x(void) const {
  return this->_x;
}

const Fixed& Point::y(void) const {
  return this->_y;
}
