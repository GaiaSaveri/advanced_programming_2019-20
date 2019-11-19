#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;
  //it gives nan, but the system doesn't crush
  //so if we are aware of the presence of a nan, we carry it
  //thruoughout all the program

  return 0;
}
