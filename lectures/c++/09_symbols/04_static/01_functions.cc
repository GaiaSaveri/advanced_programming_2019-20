#include <iostream>

//STATIC AS "REMEMBER"

void dwim() {
  static int i = 0;  // this line is executed only once
  //nothing to do with nt/ext linkage

  //means that I remember the value among different
  //remeber the last value
  //(initializet only once)
  //invocation of the function
  //leaves in the stack
  //in fortran all the  ars are static by default
  ++i;
  std::cout << i << std::endl;
}

int main() {
  dwim();
  dwim();
  dwim();
  dwim();
  dwim();
  return 0;
}
