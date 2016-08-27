#include "Printable.h"

class Shape : public Named {
public:
  Shape ( std::string const & name ) : Named ( name ){
    quantity++;
  }

  virtual ~Shape( ){
    quantity--;
  }
  static int GetCount(){
    return quantity;
  }
private:
  static int quantity;
};
