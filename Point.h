#ifndef POINT_H
#define POINT_H

class Point
{
public:
  Point();
  Point(int x, int y);
  ~Point();

  int x, y;
};

Point::Point() : x{0}, y{0} {}

Point::Point(int _x, int _y) : x{_x}, y{_y} {}

Point::~Point() {}

bool operator==(Point& p1, Point& p2) {
  return (p1.x == p2.x && p1.y == p2.y);
}

bool operator!=(Point& p1, Point& p2) {
  return !(p1 == p2);
}

#endif
