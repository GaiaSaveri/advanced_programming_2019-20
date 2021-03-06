#include <iostream>

//way to organize symbols and avoid name conflicts 
namespace choose_a_name {

  int variable;

  namespace nested {
    //namespace defined inside another namespace
    void hello1();
    void hello2();
    void hello3();

  }  // namespace nested
}  // namespace choose_a_name

int main() {
  // variable = 42; // error
  choose_a_name::variable = 42;
  //variable is a fully qualified name
  
  // hello1(); // error
  choose_a_name::nested::hello1();
  choose_a_name::nested::hello2();
  choose_a_name::nested::hello3();
  return 0;
}

//functions defined in a namespace can be implemented 
//outside the namespace but with the fully qualified name
void choose_a_name::nested::hello1() {
  std::cout << "hello1 from nested\n"
            << "variable is " << choose_a_name::variable << std::endl;
}

//or we can reopen the namespace to define the function
namespace choose_a_name {
  namespace nested {
    void hello2() {
      std::cout << "hello2 from nested\n"
                << "variable is " << variable << std::endl;
    }
  }  // namespace nested
}  // namespace choose_a_name

using namespace choose_a_name;

void nested::hello3() {
  std::cout << "hello3 from nested\n"
            << "variable is " << variable << std::endl;
}
