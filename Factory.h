#include "Shapes.h"
enum{
  POINT,
  CIRCLE,
  RECT,
  SQUARE,
  POLYLINE,
  POLYGON
};

Shape * newFigure ( int type ){
  switch ( type ) {
    case POINT:
      Shape * shape = new Point ("noname", 1, 2);
      return;
    case CIRCLE:
      return;
    case RECT:
      return;
    case SQUARE:
      return;
    case POLYLINE:
      return;
    case POLYGON:
      return;

  }
}
