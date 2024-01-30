#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"


class Triangle : public Shape
{
    Point vertices [3];
    double side;
    public:
        Triangle(const Point& c = Point(0,0),const Point& p0 = Point(0,1));
        Triangle(const Triangle& s0);
        double getSide() { return side; } /**< oldalhossz */

        bool contains(const Point& p0) const; /**< Pont benne van-e  */
        bool isInCircle(double rad) const; /**< Ütkozik-e az origócentrikus adott sugarú körrel */
        void display() const; /**< kiírja konzolra a csúcsokat */

        void write(std::ostream& os) const;

        void read(std::istream& is);

};

#endif // TRIANGLE_H
