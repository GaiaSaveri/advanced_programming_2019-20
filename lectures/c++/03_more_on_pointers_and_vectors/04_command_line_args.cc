#include <iostream>

int main(int argc, char* argv[])
//argc:non-negative value representing the number of arguments
//passed to the program from the environment in which the program is run
//same is char** argv
//argv: pointer to the first element of an array of argc + 1 pointers,
//of which the last one is null and the previous ones, if any,
//point to null-terminated multibyte strings
//that represent the arguments passed to the program
//from the execution environment.
//If argv[0] is not a null pointer (or, equivalently, if argc > 0),
//it points to a string that represents the name used to invoke the program,
//or to an empty string. 
{
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
