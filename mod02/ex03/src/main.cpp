#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

float getPointOrientation(const Point& p, const Point& a, const Point& b) {
  Fixed res = (p.x() - b.x()) * (a.y() - b.y()) - (a.x() - b.x()) * (p.y() - b.y());
  return res.toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float o1 = getPointOrientation(point, a, b);
  float o2 = getPointOrientation(point, b, c);
  float o3 = getPointOrientation(point, c, a);

  bool has_neg = (o1 < 0) || (o2 < 0) || (o3 < 0);
  bool has_pos = (o1 > 0) || (o2 > 0) || (o3 > 0);

  return !(has_neg && has_pos);
}

int main( void ) {
    Point a(0, 0);
    Point b(5, 0);
    Point c(2.5f, 5);
    Point p(2.5f, -1);

    if (bsp(a, b, c, p)) {
        std::cout << "Point is inside the triangle." << std::endl;
    } else {
        std::cout << "Point is outside the triangle." << std::endl;
    }

    return 0;
}
