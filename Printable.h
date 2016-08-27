#include "Named.h"

class Printable : public virtual Named{
public:
  Printable (std::string const & name) : Named(name){};
  virtual void print(std::ostream & out) = 0;
  friend std::ostream & operator << (std::ostream & out, Printable & shape){
    shape.print(out);
    return out;
  }
  virtual ~Printable ();

};
