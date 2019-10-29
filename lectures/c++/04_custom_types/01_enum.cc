#include <iostream>

enum color { red, yellow, green };
// enum color{red=0, yellow=1, green=2}; // equivalent
//if we want two of them that happens together it is convient
//to assign power of 2 (only 1bit)
//way to have different constants, named constants
//we are defining the type color, technically they are integers

//metti const expression nel file di conersione da m a inch


void dwim(const color c) {
  //switch is handful when we have a lot of if statements
  switch (c) {
    case red:
      std::cout << "option 1: red\n";
      break; //if we don't put break it will analizes also the other cases
    case yellow:
      std::cout << "option 2: yellow\n";
      break;
    case green:
      std::cout << "option 3: green\n";
      break;
    default: //recommended default option
      std::cout << "unknown option\n";  // should I exit the program?
      break;
  }
}

int main() {
  color opt{red};
  // opt = 3; // cannot assign int to enum error at compile time
  int a{opt};  // but they implicitly converts to integers

  dwim(opt);

  dwim(yellow);

  // dwim(2); // error at compile time
  dwim(color(2));  // works but why you may want to write this?

  dwim(color(6));  // it works, bt since we don't have 6 colors it's dangerous

  return 0;
}
