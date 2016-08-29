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
  ~Point (){};
private:
  float _x, _y;
};
