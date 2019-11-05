#include <iostream>
#include <string>
//something in the heap without using new
//constructors: functions that are invoked when you define the objects
//can have many constructors
//but only one destruptor
//the destruptor is used when a variable goes out of scope
//scope: space inside {}
//delete call the destruptor, new call the constructor

//constructor is a member function of a class
//which initializes objects of a class

//constructor have the same name as the class
//same syntax as functions but without a return type
//if we don't specify a constructor, the compiler genrate a default constructor

struct Foo {
  int _i;
  double _d;
  std::string _s;

  Foo(const int i, const double d,
      const std::string& s);  // custom constructor (declaration)
  //paremetrized constructor
  //we can implement things inside or outside the class
  //function that are defined inside the class are inlined
  //copy and paste a copy of the function
  //small functions are better inlined (less than 3-4 lines)
  //however there is no way to know if a compiler inlines the function or not
  //outside are not inlined

  Foo();  // default constructor
  //needed for example if we want to have an array of this object

  ~Foo();  // destructor
};

//fully qualified name of a constructor
Foo::Foo(const int i, const double d, const std::string& s)
  //constructors are special functions
  //region before {} is allowed only when defining a constructor
  //inside this region we should invoke constructor of the vars
  //in this way we construct vars with the right value
    : _i{i}, //universal, uniform inizializer is allowed here
      _d{d},
      _s{s}
// _i, _d, _s must be initialized in the same order they have been declared

{
  //_i{i}; here in the body is a compile error
  //in the body of the constructor everything is aleady constructed
  //but we can do
  // _i = i; //this is assign i to _i, which is already constructed
  //more operations than above
  std::cout << "custom ctor\n";
  // if you want/need you can use _i, _d, _s and change their value
  // with the usual notation +,-,=,*, call a function..
  // don't use {} because this notation is reserved for the
  // construction of the variables and at this point they have already
  // been constructed
}

Foo::Foo() {
  std::cout << "default ctor\n";  // what happens to our member variables?
}

//default destruptor
Foo::~Foo() {
  std::cout << "dtor\n";
}

//operator are spacial functions
//functions with special name
//in this case we want to overload << operator
//the overload operator must be defined outside the class
//at least one of its operands has a class type or an enumeration time
//overload operators are expected to work as similar as possible to the built in
std::ostream& operator<<(std::ostream& os, const Foo& f) {
  os << f._i << " " << f._d << " " << f._s << std::endl;
  return os; //by reference
}


int main() {
  Foo f0;    // call default ctor
  Foo f1{};  // call default ctor
  // Foo f2(); // compiler error,
  //the compiler things that we are trying to call a function

  Foo f2{8, 2.2, "hello"};
  //custom costructor
  //can be called also with ()
  std::cout << "f0: " << f0 << "f1: " << f1 << "f2: " << f2 << std::endl;
  //we first we do std::cout << "f0: "
  //call of <<
  //then again and again

  //we destruct from bottom to top (lifo)
  
  // the destructor is called when the variable goes out of scope
  //never invoke a destructor by hand
  return 0;
}
