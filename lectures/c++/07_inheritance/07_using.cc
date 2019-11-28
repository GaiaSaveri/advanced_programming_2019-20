#include <iostream>

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  //with this we allow overloading
  using foo::f;  // brings all foo::f to this scope
  //overloading (not overriding) types are different
  void f(char x) { std::cout << "char " << x << std::endl; }
};
//overloading is not resolving across hierarchy

int main() {
  bar b;
  b.f(33); //without using foo::f this prints char!
  //with using foo::f since we allow overloading
  //and 33 is an int we have int
}
