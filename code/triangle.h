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
        bool isInCircle(double rad) const; /**< �tkozik-e az orig�centrikus adott sugar� k�rrel */
        void display() const; /**< ki�rja konzolra a cs�csokat */

        void write(std::ostream& os) const;

        void read(std::istream& is);

};

#endif // TRIANGLE_H
