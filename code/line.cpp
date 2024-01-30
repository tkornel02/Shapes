#include "point.h"
#include "line.h"
#include <cmath>
#include "memtrace.h"

bool Line::pointOnLine(const Point& p1)const {
    //A távolsága p1-tõl
    double d1 = a.distanceFrom(p1);
    //B távolsága p1-tõl
    double d2 = b.distanceFrom(p1);

    //a double-ok pontatlansága miatt kell egy küszöb (minél kisebb szám annál pontosabb)
    double buffer = 0.01;

    //Ha a két távolság összege (nagyjából) megegyezik a szakasz hosszával akkor rajta van a szakaszon
    if ( d1+d2 >= length()-buffer && d1+d2 <= length()+buffer ){
        return true;
    }

    return false;
}

bool Line::circleOnLine(const Circle& c1) const {
    //Ha az egyik végpont benne van a körben akkor metszik egymást
    bool inside1 = c1.contains(a);
    bool inside2 = c1.contains(b);
    if (inside1 || inside2) return true;

    //Skalaris szorzata (dot product)
    double dot = ( ((c1.getCenter().getX()-a.getX())*(b.getX()-a.getX())) + ((c1.getCenter().getY()-a.getY())*(b.getY()-a.getY())) ) / pow(length(),2);

    //Legkozelebbi pont koordinatainak kiszamitasa
    double closestX = a.getX() + (dot * (b.getX()-a.getX()) );
    double closestY = a.getY() + (dot * (b.getY()-b.getX()) );

    //Megnezzuk hogy rajta van-e egyaltalan a szakaszon a legkozelebbi pont
    //Ha nem, akkor nem metszi
    Point closest(closestX,closestY);
    bool onSegment = pointOnLine(closest);
    if (!onSegment) return false;

    //Ha a legkozelebbi pont benne van a korben akkor van metszes
    return (c1.contains(closest));

}



