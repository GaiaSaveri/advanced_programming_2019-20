#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);
//const helps the compiler to optimize the code
int main() {
  int a{8}, b{7}; 
  int* pi{&a}; //pointer to integer initialized with the address of a
  //apply const to a pointer
  //suggestion: read from right to left to understand
  const int* pc{&a}; //cannot change the pointer when you dereference
  // *pc = 7; 	// error at compile time
  a = 15;  // I can obviously change a

  int* const cp{&a};//cannt change the value of cp
  //cannot change the address
  //the can change the value of the variable pointed by cp
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc{&a};

  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}
//an array decays to a pointer to its first element
template <typename T>
//this is the way I can pass an array to a function
void print_sentinel(const T* a, const std::size_t l)
//can change a but not the value pointed to by a
{ const T* const end{a + l} //a points to the first element, l is the size
  //in this way you point the last element of the array
  for (; a != end; ++a)
    //before the beginnin of the first iteration I do nothing
    //exit when pointing the last cell of the array
    std::cout << *a << std::endl; //deference a,
    //so I read the value in the cell pointed by a
}
