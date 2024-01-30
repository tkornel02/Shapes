#include "square.h"
#include "circle.h"
#include "line.h"
#include <cmath>
#include "memtrace.h"
#include <iostream>
#include <iomanip>
#undef M_PI
#define M_PI 3.1415
Square::Square(const Point& c,const Point& p0)  :Shape(c,p0) {

        /// Tengelyekhez igazitott negyzettel dolgozunk ezert kell ellenorizni
        ///Double-ok miatt kuszobindex
        double absX = fabs(c.getX()-p0.getX());
        double absY = fabs(c.getY()-p0.getY());

        double buffer = 0.001;
        if (fabs(absX-absY) >= buffer){
                std::cout << "Invalid parameters:\n";
                this->write(std::cout);
                throw "Invalid square.\n";
        }
        Point temp = p0;
        //Kozeppont koruli forgatassal (90 fok = pi/2) kapjuk meg a csucsokat

        for (size_t i = 0; i < 4; i++){

            vertices[i] = temp.rotateBy((M_PI/2), c);
        }
        side = (2/sqrt(2)) * c.distanceFrom(p0);
    }


/** Copy Konstruktor*/
Square::Square(const Square& s0) : Shape(s0.getCenter(),s0.getCorner()){
    *this = Square(s0.getCenter(),s0.getCorner());

}

void Square::display() const{
        std::cout << "Negyzet "<< getCenter() << " " << getCorner();
    std::cout << std::endl;
}


/**< Checks if point in Square */
bool Square::contains(const Point& p0) const{
    bool collision = false;

  // go through each of the vertices, plus
  // the next vertex in the list
  int next = 0;
  for (int current=0; current<4; current++) {

    // get next vertex in list
    // if we've hit the end, wrap around to 0
    next = current+1;
    if (next == 4) next = 0;

    // get the PVectors at our current position
    // this makes our if statement a little cleaner
    Point vc = vertices[current];    // c for "current"
    Point vn = vertices[next];       // n for "next"

    // compare position, flip 'collision' variable
    // back and forth
    if (((vc.getY() >= p0.getY() && vn.getY() <= p0.getY()) || (vc.getY() <= p0.getY() && vn.getY() >= p0.getY())) &&
         (p0.getX() < (vn.getX()-vc.getX())*(p0.getY()-vc.getY()) / (vn.getY()-vc.getY())+vc.getX())) {
            collision = !collision;
    }
  }
  return collision;

}

/**< Checks overlapping between Square and an origin-centric Circle   */
bool Square::isInCircle(double rad) const {
    Circle c(Point(0,0), Point(rad,0));

  // go through each of the vertices, plus
  // the next vertex in the list
  int next = 0;
  for (int current=0; current<4; current++) {

    // get next vertex in list
    // if we've hit the end, wrap around to 0
    next = current+1;
    if (next == 4) next = 0;

    // get the PVectors at our current position
    // this makes our if statement a little cleaner
    Point vc = vertices[current];    // c for "current"
    Point vn = vertices[next];       // n for "next"
    Line vl(vc,vn);
    // check for collision between the circle and
    // a line formed between the two vertices
    bool collision = vl.circleOnLine(c);
    if (collision) return true;
  }

  // the above algorithm only checks if the circle
  // is touching the edges of the polygon – in most
  // cases this is enough, but you can un-comment the
  // following code to also test if the center of the
  // circle is inside the polygon

  bool centerInside = contains(c.getCenter());
    if (centerInside) return true;

  // otherwise, after all that, return false
  return false;

}

void Square::write(std::ostream& os) const
{
    os << "PSquare" << std::endl;
    os << getCenter() << std::endl;
    os << getCorner() << std::endl;
}

void Square::read(std::istream& is)
{
    std::string tmp;
    getline(is, tmp);
    if (tmp != "PSquare")
        throw std::out_of_range("PSquare read error\n");
    Point p;
    (is >> p).ignore(1);
    setCenter(p);
    (is >> p).ignore(1);
    setCorner(p);
}
