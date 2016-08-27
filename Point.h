#include "Shape.h"

class Point : public Named{
public:
  Point (std::string const & name, float x, float y) : Named( name ){
    _x = x;
    _y = y;
  }
  virtual ~Point ();
private:
  float _x, _y;
};
