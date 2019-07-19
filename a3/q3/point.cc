#include "point.h"

Point::Point(int x, int y) : a{x}, b{y} {}

int Point::x() const {
    return a;
}

int Point::y() const {
    return b;
}

Point maxPoint(Point & p1, Point p2) {
    return Point(p1.a > p2.a ? p1.a : p2.a, p1.b > p2.b ? p1.b : p2.b);
}

Point Point::operator+(const Point & other) const{
    return Point{(a+other.a),(b+other.b)};
}

std::ostream & operator<<(std::ostream & out, const Point & point){
    return out << "(" << point.a << "," << point.b << ")";
}






