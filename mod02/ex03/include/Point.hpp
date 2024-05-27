#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
  public:
    Point(void);
    Point(const Fixed& x, const Fixed&y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point(void);

  private:
    const Fixed _x;
    const Fixed _y;
};

#endif // !DEBUG
