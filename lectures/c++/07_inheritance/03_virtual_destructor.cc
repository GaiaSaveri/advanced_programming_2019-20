#include <iostream>
//if there are no virtual functions in a class
//thing before putting the virtual distructor
//because we pay a runtime penalty (jumps)
struct Base {
  Base() { std::cout << "Base\n"; }
  ~Base() { std::cout << "~Base\n"; }
};//size 1

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};//size 1

int main() {
  { Derived d;
    //within this scope it is constructed and destroyed
  }

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p; //with this I invoke the destructor of base
  //not the detsructor of Derived --> memory leak!!
  //when we know that a class must be inherited
  //make the destructor virtual
  //but be carefull to put too many virtual functions
  //bc of dimension penalty, from 1 to 8!

  //benchmark-->counting operations and measuring the time
  
  //we can construct a (templated) wrapper s.t. evry time a ctor is invoked
  //it keeps track in a counter and so on

  //semiregular
  //regular: equality comparison == is defined
  //totally ordered: <, <=, >, >= are defined
  

  return 0;
}

//we construct from top to bottom
//destroy from bottom to top
