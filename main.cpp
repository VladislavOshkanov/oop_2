#include "Shapes.h"
int main() {

  Point * center = new Point ( "point", 1, 2);
  Circle * a = new Circle("circle", center, 3);
  std::cout << Shape::getCount() << std::endl;
  a->print(std::cout);
  delete a;
  std::cout << Shape::getCount() << std::endl;

  return 0;
}
