#include "Shape.h"

class Point : public Shape{
public:
  Point (std::string const & name, float x, float y) : Shape( name ){
    _x = x;
    _y = y;
  }
  void print(){
    
  }
  virtual ~Point ();
private:
  float _x, _y;
};
