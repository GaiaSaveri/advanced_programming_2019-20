#include<string>
#include<algorithm>
#include<iostream>

std::string to_upper(const std::string& os)
{
  static int n;
  ++n;
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)-> unsigned char { return std::toupper(c);});
  std::cout << "function " << __func__  << " has been called " << n << " times\n";
  return s;
}

std::string to_lower(const std::string& os)
{
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)-> unsigned char { return std::tolower(c);});
  return s;
}
