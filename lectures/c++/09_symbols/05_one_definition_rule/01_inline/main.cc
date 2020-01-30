#include "src1.h" //both have funct.h
#include "src2.h"

//if we remove inline
//when we link we got mult def of dummy

int main() {
  dummy1();
  dummy2();
  return 0;
}
