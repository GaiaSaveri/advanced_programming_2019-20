#ifndef __class__
#define __class__

#include <iostream>



template <class T = double>
struct A {
  T a;
  A();
};

//fine also to have ultiple def 
//of a member function of a class
//because it is a templated function

//ok to keep templated class in a header
//one def rule for templated things is less strict than for 
//non templated things
template <class T>
A<T>::A() {
  std::cout << "A ctor\n";
}

#endif
