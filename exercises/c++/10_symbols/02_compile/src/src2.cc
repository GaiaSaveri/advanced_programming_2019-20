#include <iostream>

namespace src2
{
std::string greetings()
{
  std::string s{"Good afternoon\n"};
  return s;
}
}

extern std::string to_lower(const std::string& os);

void print_lower(const std::string& s)
{
  std::string a = src2::greetings();
  std::cout << to_lower(a);
  std::cout << to_lower(s) << std::endl;
}
