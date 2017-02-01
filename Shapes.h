#include "Base.h"
#include <math.h>
class Point : public Shape, public Named{
public:
  Point ( std::string const name, float x, float y ) : Shape(), Named ( name ){
    _x = x;
    _y = y;
  }
  void print( std::ostream & out ){
    out << "Point: \n \tName: " << this->getName() << "\n" << "\tCoordinates:(" << _x << "," << _y << ") \n";
  }
  ~Point (){
    std::cout << "destructor of point" << '\n';
  };
private:
  float _x, _y;
};

class Circle : public Shape, public Named{
public:
  Circle (std::string const name, float x, float radius) : Shape(), Named ( name ){
    _center = new Point ( "center", x, y );
    _radius = radius;
  }
  void print( std::ostream & out ) {
    out << "Circle: center:";
    _center->print(out);
    out << "\tradius:" << _radius << "\n";
    out << "\tspace:" << _radius * _radius * M_PI << "\n";
  }
  ~Circle (){
    delete  _center;
    std::cout << "destructor of circle" << '\n';
  };
private:
  Point * _center;
  float   _radius;
};
class Rect {
public:
  Rect (std::string const name, );
  virtual ~Rect ();
private:
};
