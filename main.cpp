#include "Factory.h"

int main() {
 srand ( time ( 0 ) );
 Container <Shape*> figures;
 for (int i = 0; i < 30; i++) {
   int type = rand() % 6;
   figures.pushLast( newFigure( type ) );
 }
 std::cout << Shape::getCount() << '\n';
 for (int i = 0; i < figures.getSize(); i++) {
   Shape * sh = figures.getNth ( i );
   delete sh;
   //sh->print(std::cout);
 }
 figures.empty();

 std::cout << Shape::getCount() << '\n';
}
