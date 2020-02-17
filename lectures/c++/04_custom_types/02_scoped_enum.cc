#include <iostream>

enum class color { red, yellow, green };//note the use of class
// enum class color{red=0, yellow=1, green=2}; // equivalent
//Each enumerator becomes a named constant of the enumeration's type
//which is contained within the scope of the enumeration,
//and can be accessed using scope resolution operator.
//There are no implicit conversions from the values of a scoped enumerator
//to integral types, although static_cast may be used
//to obtain the numeric value of the enumerator. 

void dwim(const color c) {
  switch (c) {
  case color::red: //:: is the operator called scope qualifier
      std::cout << "option 1: red\n";
      break;
    case color::yellow:
      std::cout << "option 2: yellow\n";
      break;
    case color::green:
      std::cout << "option 3: green\n";
      break;
    default:
      std::cout << "unknown option\n";  // should I exit the program?
      break;
  }
}

//the purpose of scoped enum is to allow different anums in the same scope
//to use the same names for their values

int main() {
  color opt{color::red};//inizialization
    // opt = 3;     // cannot assign int to enum
  // int a = opt; // and they don't implicitly convert to integers
  int a{static_cast<int>(opt)};  // cast
  // int a {int(opt)}; //
  // int a {(int)opt}; // C-style cast

  dwim(opt);

  dwim(color::yellow);

  // dwim(2); // error
  dwim(color(2));  // works but what why you may want to write this?

  dwim(color(6));  // ???

  return 0;
}
