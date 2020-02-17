#include <iostream>

//STATIC MEMBERS

struct Foo {
  //as in count operations
  //static for a class' member
  static double s;  // must be defined outside the class
  // static int si = 0; // error: must be const for being initialized
  //syntax is quite tricky!
  static const int sc = 9;  // only integral types are allowed
  //for static vars that are const
 
  // static const double sd;  // error
  int i;
}; //size of the class foo is the size of int
//all the objects of type foo share the same static variables

double Foo::s; //COMPULSORY //same as the s before
//this is the declaration for static double s
//fully qualified name
//as it was a global var

//double Foo::s = 0; --> ok
// double Foo::s = 9; --> ok

// int Foo::i = 2; // error, only static members can be defined out of class

int main() {
  Foo::s = 77.88;
  Foo f1;
  Foo f2;
  std::cout << sizeof(f1) << std::endl;
  std::cout << f1.s << '\n' << f2.s << '\n' << Foo::s << std::endl;
  return 0;
}
