#ifndef LINE_H
#define LINE_H
#include "circle.h"

class Line {
    Point a; //!< kezdopont "a"
    Point b; //!< vegpont "b"
public:
        /// Konstruktor
       Line(const Point& p1,const Point& p2): a(p1), b(p2){}

       /** Szakasz hossza*/
       double length() const {return a.distanceFrom(b);}

       /** Pont ellen�rz�se hogy rajta van-e a vonalon  */
       bool pointOnLine(const Point&) const;

        /**< K�r �s szakasz metszi-e egym�st */
       bool circleOnLine(const Circle&) const;
};


#endif // LINE_H
