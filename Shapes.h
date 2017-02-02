#include "Base.h"
#include <math.h>
class Point : public Shape, public Named{
public:
  Point ( std::string const name, float x, float y ) : Shape(), Named ( name ){
    _x = x;
    _y = y;
  }
  Point ( const Point & obj ): Shape(), Named( obj._name ){
      _x = obj._x;
      _y = obj._y;
      std::cout << "\nКонструктор копирования\n";
  }
  void print( std::ostream & out ){
    out << "Point: \n \tName: " << this->getName() << "\n" << "\tCoordinates:(" << _x << "," << _y << ") \n";
  }
  float getX(){
    return _x;
  }
  float getY(){
    return _y;
  }

  ~Point (){
    std::cout << "destructor of point" << '\n';
  };
private:
  float _x, _y;
};

class Circle : public Shape, public Named{
public:
  Circle (std::string const name, Point * x, float radius) : Shape(), Named ( name ){
    _center = new Point (*x);
    _radius = radius;
  }
  void print( std::ostream & out ) {
    out << "Circle:\n center:";
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
  Rect ( std::string const name, Point * ul, Point * dr ) {
    _ul = new Point(*ul);
    _dr = new Point(*dr);
  };
  ~Rect (){
    std::cout << "destructor of rect" << '\n';
    delete _ul;
    delete _dr;
  };
  float calculateSpace(){
    return ( _ul->getY() - _dr->getY() )*( _dr->getX() - _dr->getY() );
  }
  void print( std::ostream & out ) {
    out << "Rectangle:\n\tUp left:";
    _ul -> print( out );
    out << "\tDown right:";
    _dr -> print ( out );
  }
private:
  Point * _ul, * _dr;  //ul - up left, dr - down right
};
