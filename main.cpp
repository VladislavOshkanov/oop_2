#include "Shapes.h"
int main() {

  Point * a = new Point ( "aaa", 1, 1 );
  Point * b = new Point ( "bbb", 1, 2 );
  //Point * c = new Point ( "ccc", 1, 3 );

  Polygon * pol = new Polygon ("pol");

  pol -> AddPoint( *a );
  pol -> AddPoint( *b );
  delete a;
  delete b;
  pol -> print(std::cout);
  delete pol;
  // std::cout << Shape::getCount() << '\n';
  return 0;
}
