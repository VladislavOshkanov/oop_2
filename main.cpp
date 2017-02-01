#include "Shapes.h"
int main() {

  Point * a = new Point ( "point", 1, 5);
  Point * b = new Point ( "point", 4, 2);
  Rect * r = new Rect("pryamougolnik", a, b);

  std::cout << Shape::getCount() << std::endl;
  r->print(std::cout);
  delete r;
  std::cout << Shape::getCount() << std::endl;

  return 0;
}
