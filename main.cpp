#include "Shapes.h"
int main() {

  Circle * a = new Circle("circle", 1, 2, 3);
  // Point * a = new Point ( "point", 1, 2);
  std::cout << Shape::getCount() << std::endl;
  a->print(std::cout);
  delete a;
  std::cout << Shape::getCount() << std::endl;

  return 0;
}
