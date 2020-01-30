#include "constants.h"
#include <iostream>

int circle_counter{0};

//void foo()
//nm -C circle.o
//function upper case external linkange
//static void foo()
//nm --> lower case, internal linkage

//symbols can have internal or exteral linkage
//when we want something internal use static kw
//if we are dealing with global var use extern

double area_circle(const double r) {
  std::cout << "[circle] pi = " << pi << std::endl;
  ++circle_counter;
  return pi * r * r;
}
