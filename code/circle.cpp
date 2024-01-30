#include "point.h"
#include "shape.h"
#include "circle.h"
#include <iostream>

    Circle::Circle(const Circle& s0) : Shape(s0.getCenter(),s0.getCorner()){*this = Circle(s0.getCenter(),s0.getCorner());}


    bool Circle::contains(const Point& p0) const{
        //Distance between center and p0
        double distance = getCenter().distanceFrom(p0);

        //If distance less than Radius => p0 is in the circle
        if (distance <= radius) {return true;}

        return false;
    }

    bool Circle::isInCircle(double originRad) const{
        Point origin(0,0);
        // If Distance between origin and center point is less than sum of radiuses => the Circles overlap
        return (origin.distanceFrom(getCenter()) <= originRad+radius);
    }

void Circle::display() const{
        std::cout << "Kor "<< getCenter() << " " << getCorner();
    std::cout << std::endl;
}

void Circle::write(std::ostream& os) const
{
    os << "PCircle" << std::endl;
    os << getCenter() << std::endl;
    os << getCorner() << std::endl;
}

void Circle::read(std::istream& is)
{
    std::string tmp;
    getline(is, tmp);
    if (tmp != "PCircle")
        throw std::out_of_range("PCircle read error\n");
    Point p;
    (is >> p).ignore(1);
    setCenter(p);
    (is >> p).ignore(1);
    setCorner(p);
}


