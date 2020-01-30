#include "constants.h"
#include <iostream>

double area_circle(const double); //need to wright the signature
//beacuase circle.cc is not an header
double golden_ratio(const double);
extern int circle_counter; //if we omit extern
//when we link all together the linker would say
//that there are two global vars with same name and same type
//ld is the linnker in linux
//ld complains

//if this var was defined in a header and we include the header
//the linker complains about mult def of pi and phi
//because include means copy and paste


//hence: nothing --> compiler complains
//     no extern --> ld complains

int main() {
  std::cout << area_circle(1) << std::endl;
  std::cout << area_circle(2) << std::endl;

  std::cout << golden_ratio(1) << std::endl;

  std::cout << circle_counter << std::endl; //global variable defined in a different compilation unit
  //if we don't put external int circle_counter
  //if we put the linker we will get a duplication of symbols
  std::cout << "[main] pi = " << pi << std::endl;

  return 0;
}

//to see how to compile
//write make -n
//the linker is in the last line of this
//everything is linked together into an executable
