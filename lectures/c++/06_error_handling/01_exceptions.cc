#include <cmath>
#include <iostream>

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

struct Negative_number {};
//empty body
struct Bigger_than_expected {};

int main() {
  //main is composed by try box + catch box
  //try catch can be at any function, not only the main
  //one try, more catch
  try {
    //we place a portion of code under inspection within a try-block
    //when we have an exception the control is made by
    //the exceptions handler
    //exception is thrown using the throw keyword inside the try
    //exception handlers are declared with catch
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    auto d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } //can detect 2 errors, negative argument or bigger than a treshold
  catch (const Negative_number) {
    std::cerr << "The square root of a negative number is a complex number.\n"
                 "square_root() is "
              << "limited to handle positive double numbers.\n";
    //these explanations is something that we want to write them in a different place
    return 1; //exit from the main
  } catch (const Bigger_than_expected) {
    std::cerr << "The function square_root has been called with a parameter "
                 "greater than 50.\n"
              << "This means there is a bug in the algorithm that generated "
                 "this number.\n";
    return 2;
  } catch (...) { //syntax to get all the rest, unknown exception
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions, check validity of the input
  //(post-condition: check before the function returns)
  if (d < 0)
    throw Negative_number{}; //default constructor
  //construct an object negative number
  //  throw accepts only one parameter which is passed as argument to the
  //exception handler catch
  if (d > 50)
    throw Bigger_than_expected{};
  return std::sqrt(d);
}
