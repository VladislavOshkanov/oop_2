#include "Printable.h"
class Named : public Printable{
public:
  Named (std::string name) : Printable(){
    this->_name = name;
  };
  virtual ~Named () {}
  void print (std::ostream & out){
    out << this->getName();
  }
  std::string const & getName() {
    return _name;
  }
private:
  std::string _name;

};
