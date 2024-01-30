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
    ///K�t pont t�vols�ga
    double distanceFrom(const Point& p2) const;

    ///Egyenl�s�gvizsg�lat
    bool operator==(Point p0)const{return x==p0.getX() && y==p0.getY();}

    ///Pont eltol�sa
    Point& offset(double distanceX=0,double distanceY=0);

    ///Pont forgat�sa
    Point& rotateBy(double angle,const Point& aroundThis);

    ///Ertekado operator
    Point& operator=(const Point& p0);

    ///Pont koordinatait javitja hogy olvashatobb legyen
    void roundPoint();
};
///Pont ki�r�sa ostream t�pus� objektumra (f�zhet�)
std::ostream& operator<<(std::ostream& os, Point p);

///Pont beolvas�sa istream t�pus� objektumr�l (f�zhet�)
std::istream& operator>>(std::istream& is, Point& p);

#endif // POINT_H_INCLUDED
