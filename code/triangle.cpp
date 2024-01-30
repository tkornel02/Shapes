#include "triangle.h"
#include "circle.h"
#include "line.h"
#include <cmath>
#include "memtrace.h"

#undef M_PI
#define M_PI 3.1415
Triangle::Triangle(const Point& c,const Point& p0) : Shape(c,p0){
        /// Tengelyekhez igazitott szabalyos haromszoggel dolgozunk ezert kell ellenorizni
        /// A forditott szabalyos haromszog is jo, tehat:
            /**
                                   ______
                     /\            \    /
                    /  \    vagy    \  /
                   /____\            \/

            */

        double absX = fabs(c.getX()-p0.getX());
        double absY = fabs(c.getY()-p0.getY());

        /// Double-ok miatt kuszobindex
        double buffer = 0.001;
        if (fabs(absX-absY*2) >= buffer){
            if (absX == 0){}
            else {
                std::cout << "Invalid parameters:\n";
                this->write(std::cout);
                    throw "Invalid triangle.\n";
                }
        }

        Point temp(p0);
        //Kozeppont koruli forgatassal (120 fok = pi*2/3) kapjuk meg a csucsokat
        vertices[0] = p0;
        for (size_t i = 1; i <= 2; i++){
            vertices[i] = temp.rotateBy( M_PI*2/3, c);
        }
        side = (3/sqrt(3)) * c.distanceFrom(p0);
    }


/** Copy Konstruktor*/
Triangle::Triangle(const Triangle& s0) : Shape(s0.getCenter(),s0.getCorner()){
    *this = Triangle(s0.getCenter(),s0.getCorner());

}
bool Triangle::contains(const Point& p0) const{
    bool collision = false;

  // go through each of the vertices, plus
  // the next vertex in the list
  int next = 0;
  for (int current=0; current<3; current++) {

    // get next vertex in list
    // if we've hit the end, wrap around to 0
    next = current+1;
    if (next == 3) next = 0;

    // get the PVectors at our current position
    // this makes our if statement a little cleaner
    Point vc = vertices[current];    // c for "current"
    Point vn = vertices[next];       // n for "next"

    ///Jordan Curve elméletet használja
    // compare position, flip 'collision' variable
    // back and forth
    if (((vc.getY() >= p0.getY() && vn.getY() <= p0.getY()) || (vc.getY() <= p0.getY() && vn.getY() >= p0.getY())) &&
         (p0.getX() < (vn.getX()-vc.getX())*(p0.getY()-vc.getY()) / (vn.getY()-vc.getY())+vc.getX())) {
            collision = !collision;
    }
  }
  return collision;
}
bool Triangle::isInCircle(double rad) const{
    Circle c(Point(0,0), Point(rad,0));

  // go through each of the vertices, plus
  // the next vertex in the list
  int next = 0;
  for (int current=0; current<3; current++) {

    // get next vertex in list
    // if we've hit the end, wrap around to 0
    next = current+1;
    if (next == 3) next = 0;

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


void Triangle::display() const{
        std::cout << "Haromszog "<< getCenter() << " " << getCorner();
    std::cout << std::endl;
}

void Triangle::write(std::ostream& os) const
{
    os << "PTriangle" << std::endl;
    os << getCenter() << std::endl;
    os << getCorner() << std::endl;
}

void Triangle::read(std::istream& is)
{
    std::string tmp;
    getline(is, tmp);
    if (tmp != "PTriangle")
        throw std::out_of_range("PTriangle read error\n");
    Point p;
    (is >> p).ignore(1);
    setCenter(p);
    (is >> p).ignore(1);
    setCorner(p);
}


