#ifndef __class__
#define __class__

#include <iostream>

struct A {
  int a;
  A() { std::cout << "A ctor\n"; }
};

// A::A() { std::cout << "A ctor\n"; } --> NO! 
// why not --> mult def of A()
//the definition of a function cannot appear many time

//outside the class in real file means another filea 
//class declaration can appear in many compilation units 
//without the linker complaining


#endif
