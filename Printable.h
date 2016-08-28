#include <iostream>
#include <string>

class Printable{
public:
  //Printable (std::string const & name) : Named(name){};
  Printable (){};
  virtual void print(std::ostream & out) = 0;
  friend std::ostream & operator << (std::ostream & out, Printable & shape){
    shape.print(out);
    return out;
  }
  virtual ~Printable ();
};
