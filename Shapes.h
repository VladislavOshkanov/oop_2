#include "Base.h"
#include "Container.h"
#include <cmath>
class Point : public Shape, public Named{
public:
  Point () : Shape (), Named(""){};
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

class Rect : public Shape, public Named{
public:
  Rect ( std::string const name, Point * ul, Point * dr ) : Shape(), Named ( name ){
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

class Square : public Shape, public Named {
public:
  Square ( std::string const name, Point * ul, Point * dr ) : Shape(), Named ( name ){
    _ul = new Point( *ul );
    _dr = new Point( *dr );
  };

  float calculateSpace(){
    return ( _ul->getY() - _dr->getY() )*( _ul->getY() - _dr->getY() );
  }

  void print( std::ostream & out ) {
    out << "Square:\n\tUp left:";
    _ul -> print( out );
    out << "\tDown right:";
    _dr -> print ( out );
  }

  ~Square (){
    delete _ul;
    delete _dr;
  };

private:
  Point * _ul, * _dr;
};
class Polyline : public Shape, public Named {
public:
  Polyline ( std::string const name ) : Shape(), Named ( name ){

  };
  void print ( std::ostream & out ){

  }
  void AddPoint ( Point const & point ){
    points.pushLast( point );
  }
  Point getFirstPoint(){
    return points.getNth(0);
  }
  float calculateLength(){
    int size = points.getSize();
    float length = 0;
    for (size_t i = 0; i <  size - 1; i++) {
      Point a = points.getNth(i);
      Point b = points.getNth(i+1);
      float diff_x = a.getX()-b.getX();
      float diff_y = a.getY()-b.getY();
      length += pow((pow(diff_x,2) + pow(diff_y,2)), 0.5);
    }
    return length;
  }
  virtual ~Polyline (){

  };
private:
   Container <Point> points;
};
