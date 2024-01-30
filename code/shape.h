#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include "point.h"
#include "serializable.h"
#include <iostream>


class Shape : public Serializable {
    Point center; /**< Kozeppontja az alakzatnak */
    Point corner; /**< egy csucsa az alakzatnak (korben a korvonal egy pontja) */
public:
    Shape(const Point& center, const Point& corner): center(center), corner(corner){}
    Shape(const Shape& sh){setCenter(sh.getCenter()); setCorner(sh.getCorner());}
    virtual bool contains(const Point& p0) const=0; /**< Checks if point in Shape */

    virtual bool isInCircle(double rad) const=0; /**< Checks overlap between Shape and an origin-centric Circle   */

    Point getCenter() const {return center;} /**< returns center point */

    Point getCorner() const {return corner;}/**< return corner  */

    void setCenter(Point p) { center = p; }

    void setCorner(Point p) { corner = p; }

    virtual void display() const=0;/**< displays attributes of Shape in console */

    virtual void write(std::ostream& os) const = 0;/**< writes attributes to standard output*/

    virtual void read(std::istream& is) = 0; /**< reads attributes from standard input*/

    virtual ~Shape(){}

};

#endif // SHAPE_H_INCLUDED
