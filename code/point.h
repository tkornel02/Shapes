#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
class Point{
    double x;
    double y;
public:

    ///Konstruktorok
    Point(double px = 0, double py = 0) : x(px), y(py){ this->roundPoint(); }
    Point(const Point& p);
    ///Getterek
    double getX()const {return x;}
    double getY()const {return y;}
    ///Két pont távolsága
    double distanceFrom(const Point& p2) const;

    ///Egyenlõségvizsgálat
    bool operator==(Point p0)const{return x==p0.getX() && y==p0.getY();}

    ///Pont eltolása
    Point& offset(double distanceX=0,double distanceY=0);

    ///Pont forgatása
    Point& rotateBy(double angle,const Point& aroundThis);

    ///Ertekado operator
    Point& operator=(const Point& p0);

    ///Pont koordinatait javitja hogy olvashatobb legyen
    void roundPoint();
};
///Pont kiírása ostream típusú objektumra (fûzhetõ)
std::ostream& operator<<(std::ostream& os, Point p);

///Pont beolvasása istream típusú objektumról (fûzhetõ)
std::istream& operator>>(std::istream& is, Point& p);

#endif // POINT_H_INCLUDED
