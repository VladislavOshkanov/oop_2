#include "Shapes.h"
int main() {

  Point * a = new Point ( "aaa", 1, 5 );
  Point * b = new Point ( "bbb", 1, 5 );
  Point * c = new Point ( "ccc", 1, 5 );

  Polyline * pol = new Polyline ("Polyline");
  pol->AddPoint( * a );
  pol->AddPoint( * b );
  pol->AddPoint( * c );

  delete pol;
  std::cout << Shape::getCount() << '\n';
  // pol->AddPoint( * b );
  // pol->AddPoint( * c );
  // pol->AddPoint( * d );
  // pol->AddPoint( * e );
  // delete a;
  Point f = pol->getFirstPoint();

  f.print(std::cout);
  return 0;
}
