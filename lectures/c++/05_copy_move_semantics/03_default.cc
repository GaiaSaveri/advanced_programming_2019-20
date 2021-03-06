#include <iostream>

struct X {
  int a = 5;  // in-class initialization
  //assign default value to some member
  double b;
  char c = 'a';
  //if we have a custom constroctur inside the class the compiler only uses that
  X() = default;  // in-class initializers are used by the constructors
  //the costructor is default generated by the compiler
  //we are asking the compiler to generate a default constructor
};

struct Y {
  int a = 77;
  double b;
  char c = 'a';
  Y() : a{5} {}  // what it is written here wins the in-class initialization
  //body of this constructor is empty
  //a is constructed as 5
  //then on the body of the constructor there is a=7 (a{7} is a mistake)
  Y(const Y&) = delete; //delete means that you cannot call this function
};

int main() {
  X x1;    // compiler-generated default ctor
  //here is x1.a=5 x1.b=uninitialized 
  X x2{};  // compiler-generated default ctor calls {} on uninitialized vars
  std::cout << x1.a << "--" << x1.b << "--" << x1.c << "\n";
  std::cout << x2.a << "--" << x2.b << "--" << x2.c << "\n\n";

  Y y1;    // default ctor --> handmade constructor --> b uninitialized
  Y y2{};  // default ctor
  std::cout << y1.a << "--" << y1.b << "--" << y1.c << "\n";
  std::cout << y2.a << "--" << y2.b << "--" << y2.c << "\n";

  // Y y3{y2}; // error: call to a deleted function

  return 0;
}
