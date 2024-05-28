#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
  public:
    Point(void);
    Point(const Fixed& x, const Fixed& y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point(void);
    const Fixed& x(void) const;
    const Fixed& y(void) const;

  private:
    Fixed _x;
    Fixed _y;
};

#endif
