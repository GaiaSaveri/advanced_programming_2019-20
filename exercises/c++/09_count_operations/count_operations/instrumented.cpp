#include "instrumented.hpp"
#include <iomanip>
#include <iostream>

// declare static variables
//necessarely outside the header file
//basically because we are defining global variables


//one def rule
//same variable declared many times in different
//compilation units
double instrumented_base::counts[];
const char* instrumented_base::counter_names[] = {
    "n",           "copy ctor", "copy assign", "move ctor", "move assign",
    "default ctr", "dtor",      "equal",       "less"};

void instrumented_base::print_header() {
  const char s = ' ';
  const int space = 12;
  for (std::size_t i = 0; i < n_ops; ++i)
    std::cout << std::setw(space) << counter_names[i] << s;
  std::cout << std::endl;
}

void instrumented_base::print_summary() {
  const char s = ' ';
  const int space = 12;
  const std::size_t n = counts[0];
  std::cout << std::setw(space) << double{counts[0]} << s;
  for (std::size_t i = 1; i < n_ops; ++i)
    std::cout << std::setw(space) << double{counts[i]/n} << s;
  //relative numbers in this way

  std::cout << std::endl;
}
