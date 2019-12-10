#include <fstream>
#include <iostream>
#include <string>
int main() {
  std::ifstream f{"a_file.txt"};
  //if we pass a file as a string
  //the file is opened with the ctor
  //and closed with the dtor
  std::string word;
  f >> word;
  std::cout << "first read word: " << word << std::endl;
  f >> word;
  std::cout << "second read word: " << word << std::endl;
  f >> word;
  std::cout << "third read word: " << word << std::endl;
  f >> word;
  std::cout << "fourth read word: " << word << std::endl;
  int a;
  f >> a;
  std::cout << "first read integer: " << a << std::endl;

  return 0;
}

//in this way we should know how to read and write files
