#include "Base.h"

class Point : public Shape, public Named{
public:
  Point ( std::string const name, float x, float y ) : Shape(), Named ( name ){
    _x = x;
    _y = y;
  }
  void print( std::ostream & out ){
    out << "Name: " << this->getName() << " Coordinates:(" << _x << "," << _y << ")";
  }
  virtual ~Point (){
    std::cout << "destructor of point" << '\n';
  };
private:
  float _x, _y;
};

class Circle : public Shape, public Named{
public:
  Circle (std::string const name, float x, float y, float radius) : Shape(), Named ( name ){
    Point  * _center = new Point ( "center", x, y );
    _radius = radius;
  }
  void print( std::ostream & out ) {

  }
  virtual ~Circle (){
    delete  _center;
    std::cout << "destructor of circle" << '\n';
  };
private:
  Point * _center;
  float   _radius;
};
