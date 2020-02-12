#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>

inline void dummy() { //if we use static we resolve the issue
//or better we use inline
//inline is a suggestion for the compiler to not put a jump
//for that function
//but copy and paste the content of the function
//only small functions
//compiler is free to ignore the suggestion

//inline implies internal linkage
//in c it doesn't happen!


//inline functions should be defined inside headers
//no more than one or two statements
  std::cout << "dummy\n";
}

#endif /* _FUNC_H_ */
