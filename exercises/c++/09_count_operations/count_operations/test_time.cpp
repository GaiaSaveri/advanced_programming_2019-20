#include "timer.hpp"
//in set_timed, all the thing to get rid of repetitions
//is accomplished by the std::set
//that creates a balanced binary tree

//traits
//implemets a templeted machinery
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

//we havea sequence of numbers
//we want to get rid of all the duplicates

timer<> t; //global variable
//need to measure the elapsed time

template <typename I>
void set_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  //typename as to be put whenever there is a nested type
  std::set<value_type> set{first, last};
  //std::set is a container
  //binary tree
  //doesn't add a key if it is already present in the tree
  //automatically get rid of duplicates
  t.stop();
}

template <typename I>
void vector_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  // std::vector<value_type> v{first, last};
  std::sort(v.begin(), v.end());
  //stor in a vector
  //sort the vector
  //then call std::unique
  //it get rid of repetitions
  auto it = std::unique(first, last); //returns an iterator 1 paseed
  //the last element different from the others
  
  t.stop();
  (void)std::distance(first,it);
}



//which of these two approaches is faster?

//vectors have to all the elements countiguos is memory
//they are faster than set!

using namespace std::chrono;
//benchmark an algorithm
//we need to seethe trend, not run only 1
//test also for different types
int main() {
  using value_type = int;
  //this for loop creates a vector
  //inizialized it with some value
  //then random shuffles
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    //n<<=1  is a bitshift operation of 1 in the left
    //stop the iteration when n is less than 2^25
    //since we did 25 shift
    std::vector<value_type> v(n);
    std::iota(v.begin(), v.end(), value_type(-1024));
    //iota-->one number different form the other
    //no repetitions
    //but we want to insert artificially repetitions
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i) {
      v[i] = int{v[i]} & 1023; //bitwise end
      //we do a bitmask so that all numbers
      //above 1023 are seen as numbers between 0 and 1023

      //e.g. if v[i] is 1024 the result of the comparison is 0
      //1025 is 1 and so on
    }
    std::cout << std::setw(15) << n << "\t";
    // set_timed(n,v.begin(),v.end());
    vector_timed(n, v.begin(), v.end());
  }
}
