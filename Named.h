#include <string>

class Named {
public:
  Named (std::string const & name){
    _name = name;
  };
  virtual ~Named () {}

  std::string const & getName() {
    return _name;
  }
private:
  std::string _name;

};
