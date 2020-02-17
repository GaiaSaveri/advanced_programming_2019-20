#include <iostream>
#include <string>

//default constructor can be invoked both with {} or without
//big difference btw built-in types and customed types

//a default constructor is a constructor that can  be invoked without arguments



struct S {
  // 2 built in type members
  int a;
  double b;
  //one member customed type
  std::string s;  // default ctor of string set s to empty string
};

int main() {
  S s1;  // calls default constructor

  S s2{1, 2.3, "alberto"};  // if there are no custom ctors I can
                            // directly initialize the members. Note
                            // that I need access (i.e. they must be
                            // public)
  // it is called aggregate initialization (see
  // https://en.cppreference.com/w/cpp/language/aggregate_initialization)
  //kind of mess btw versions of c++

  S s3{};  // calls {} on each member: S s3 { {}, {}, {} };
  //kind of default constructor but to each member
  //this way all possible uninizialized var are 0
  //for custom type "S s3;" is equivalent to "S s3{}"

  std::cout << s1.a << "--" << s1.b << "--" << s1.s << "\n";
  std::cout << s2.a << "--" << s2.b << "--" << s2.s << "\n";
  std::cout << s3.a << "--" << s3.b << "--" << s3.s << "\n";
  return 0;
}

//class with custom type we invoke by default the dfault constructor
//of that type
//indeed string is initialized by 0
//while built in type are not inizialized
