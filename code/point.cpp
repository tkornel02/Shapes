#include "point.h"
#include <cmath>
#include <iostream>
/**< Masolo konstruktor, javit a roundPoint-tal */
Point::Point(const Point& p0) {
    x = p0.getX(); y = p0.getY();
    this->roundPoint();
    }
/**< Ertekado operator, javit a roundPoint-tal */
Point& Point::operator=(const Point& p0){
    x = p0.getX();
    y = p0.getY();
    this->roundPoint();
    return *this;
}

    ///Ket pont tavolsaga
double Point::distanceFrom(const Point& p2) const {
    double distX = x - p2.getX();
    double distY = y - p2.getY();

    return sqrt( distX*distX + distY*distY );
}

    ///Eltolas
Point& Point::offset(double distX,double distY){
    x += distX;
    y += distY;
    return *this;
}
/// Forgatas
Point& Point::rotateBy(double angle,const Point& aroundThis){
    double s = sin(angle);
    double c = cos(angle);


    //Origo helyzetehez igazitjuk a forgatando pontot
    *this = offset(-aroundThis.x,-aroundThis.y);

    //segedkoordinatak
    double tempX = x;
    double tempY = y;

    //forgatjuk a koordinatakat mintha origo korul lennenk
    x = tempX * c - tempY * s;
    y = tempY * c + tempX * s;

    //visszatesszuk a relativ helyere
    *this = offset(aroundThis.x,aroundThis.y);

    //visszaterunk a forgatott pont referenciajaval (valtozott az obj)
    return *this;
}

/// Pont koordinatait javitja hogy olvashatobb legyen, hogy
///(ne legyen koordinata pl. 2.2e-16, helyette 0 lesz)
void Point::roundPoint(){
    //Kuszob idx
        double buffer = 1e-5;

    if ( fabs(x) < buffer ) {
        x = 0;
    }
    if ( fabs(y) < buffer ) {
        y = 0;
    }
}

    ///Pont kiírása ostream típusú objektumra (fûzhetõ)
std::ostream& operator<<(std::ostream& os, Point p) {
    os << "("<<p.getX() << "," << p.getY() <<")";

    return os;
}
    ///Pont beolvasása istream típusú objektumról (fûzhetõ)
std::istream& operator>>(std::istream& is, Point& p) {
    double px,py;
    char a;
    is >> a >> px >> a >> py >> a;
    p = Point(px,py);
    return is;
}
