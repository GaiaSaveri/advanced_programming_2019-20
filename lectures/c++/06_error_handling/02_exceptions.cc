#include <cmath>
#include <iostream>
#include <string>

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);
//we define a new type
struct Square_root_invalid {
  std::string message; //message will be populated in the constructor
  Square_root_invalid(const std::string& s) : message{s} {}
}; 

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    auto d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (const Square_root_invalid& s) {
    std::cerr << s.message << std::endl; //print in standard error
    //now it's not the user to write what happened
    //the developer wrapped the message for the user
    //std::cerr is the standard error stream
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions
  if (d < 0)
    //invoke contructor of struct
    //building the var message
    throw Square_root_invalid{"Cannot handle negative numbers. You gave me " +
                              std::to_string(d)};
  //more informative than the others before
  if (d > 50)
    throw Square_root_invalid{
        "The argument of square_root must be lower than 50. You gave me " +
        std::to_string(d)};
  return sqrt(d);
}
