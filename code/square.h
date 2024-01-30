#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape{
    Point vertices[4] ; //!< Csucsokat tarolja
    double side;
    public:
        Square(const Point& c= Point(0,0),const Point& p0 = Point(1,1) );
        Square(const Square&);
        double getSide() { return side; } /**< oldalhossz */

        bool contains(const Point& p0) const; /**< Pont benne van-e  */
        bool isInCircle(double rad) const; /**< �tkozik-e az orig�centrikus adott sugar� k�rrel */
        void display() const; /**< ki�rja konzolra a cs�csokat */

        void write(std::ostream& os) const;

        void read(std::istream& is);
};


#endif // SQUARE_H
