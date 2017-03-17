#include "Shapes.h"
int main() {

  Point * a = new Point ( "aaa", 1, 1 );
  Point * b = new Point ( "bbb", 1, 2 );
  Point * c = new Point ( "ccc", 1, 3 );

  Polyline * pol = new Polyline ("Polyline");
  pol->AddPoint( *a );
  pol->AddPoint( *b );
  pol->AddPoint( *c );
  delete a;
  delete b;
  delete c;
  double length = pol->calculateLength();
  std::cout << length << '\n';
  return 0;
}
