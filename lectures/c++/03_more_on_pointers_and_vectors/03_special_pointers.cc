#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc; //pointer to a pointer char, for each of these *
  //we can put the const

  int* ap[7]; //array of pointers to integers

  void* pv{pi}; //special type of pointer, we can convert any pointer to a void
//a void pointer does not know what type of object it is pointing to
//can be pointed at objects of any data type
  //but cannot dereference a pointer to a void
  //bc we don't know the size, and when we dereference we need to know the type
  //deference operator --> value pointed to by
  //we can use the casts
  //a cast is a conversion to a different type
  //a void pointer must be first explicitly cast to another pointer 
  //type before it is dereferenced
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  int* pi2{static_cast<int*>(pv)};
  //static cast is performed and checked at compile time

  pv = ppc;
  pv = ap;
  pv = pi;
  //cannot dereference nullptr --> segmentation fall
  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;  // error, why?
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr, better to use nullptr

  // pi = NULL; // please don't do this

  double* da{new double[5]{}};
  //when we allocate sth on heap, new returns an address
  delete[] da;  //to avoid  dangling pointer need to do:
  da = nullptr;
 
  if (pi != nullptr) 
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi) //is equal to the above one, 0 means false
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  //last element to understand that the stringis finished
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  int (*fp)(const char*);//this syntax with parentesis is mandatory
  //defines a pointer to a function, called fp
  //it can points to all the function that have const char* as argument
  //and return an int
  
  fp = func1;

  fp("hello"); //call the function throught its pointer

  fp = &func2; //same if I do fp=func2
  fp("world");

  // fp = func3; // error: wrong signature --> compile error
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3; //within template we cannot use auto bt decltype
  //defines a var x of type whatever is the &func3
  //actually a pointer to a function
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
