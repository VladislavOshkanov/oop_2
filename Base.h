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
