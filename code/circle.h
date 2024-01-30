#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "shape.h"
class Circle : public Shape{
    double radius;
public:

    Circle(Point center= Point(0,0), Point corner = Point(0,1)) : Shape(center,corner), radius(center.distanceFrom(corner)) {}
    Circle(const Circle& s0);
    bool contains(const Point& p0) const;

    double rad() const {
        return radius;
    }
    bool isInCircle(double originRad) const;
    void display() const;

    void write(std::ostream& os) const;

    void read(std::istream& is);

};




#endif // CIRCLE_H_INCLUDED
