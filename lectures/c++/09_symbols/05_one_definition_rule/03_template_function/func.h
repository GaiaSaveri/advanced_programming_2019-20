#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>


//no need to put static/inline
//advise: keep all templates in headers
//(do not compile templates)

//one def rule is different if the function is or isn't templated

template <class T = double>
void dummy() {
  T t{};
  std::cout << t << ": dummy\n";
}

#endif /* _FUNC_H_ */
