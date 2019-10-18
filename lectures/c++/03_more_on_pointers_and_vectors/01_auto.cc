#include <cmath>
#include <iostream>
//RECAP:
//an object that lives inthe heaphas no name
//instead in the stack they have
//the onlywayto enter an object in the heap is with pointers
//implicit convertion btw array and pointers, the array is the pointer
//to its first element
#if __cplusplus > 201103L //this cheks if the compiler supports c++14 or not
//201103L is the official string of c++11
//this if preceeded by # is evalueted before compilation starts
template <class T>
auto init(const std::size_t l) {
  return new T[l]{};//{} means that everything is initialized to 0
  //since c++14 we can use auto also as a return type of a function
  //auto is usefull for maintenability of a function
}
#else //no c++14 in the compiler

template <class T>
T* init(const std::size_t l) {
  return new T[l]{};
}

#endif
//auto is from c++11, recall that c++ is a statically and strongly typed lang.

//template <class T> //class or typename is the same in template
//void debug(T);

int main() {
  auto b = true;          // a bool
  auto ch = 'x';          // a char
  auto i = 123;           // an int (could be also unsigned int, long, short..)
  auto d = 1.2;           // a double (not float)
  auto z = std::sqrt(d);  // z has the type of whatever sqrt(d) returns
  //the signature of the function is known at compile time
  //std is a namespace
  auto ui = 0u;           // unsigned int (suffixes to force a type)
  auto llui = 0llu;       // long long unsigned int
  //universal and uniform initializer thatis {}, NOT use with auto, use = 
  for (auto i = 0; i < 7; ++i)
    std::cout << i << std::endl;

  auto pb = &b;  //pointer to a boolean
  //in order to know the type of a var we have to ask the compiler
  //forcing a compile error:
  // debug(pb); //calling a function which is not defined-->compile error
  //the compiler in this way tell me what is the tye 've given as input
  auto ps = init<double>(11);
  delete[] ps;
  return 0;
}
