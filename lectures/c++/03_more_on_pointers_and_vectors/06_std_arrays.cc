#include <array>
#include <iostream>
//definition of the array:
// template <class T, std::size_t N> //type and length
// struct array;
//std array are static and live in the stack
int main() {
  std::array<int, 4> a{1, 2, 3, 4}; //declaration of an std array
  std::array<int, 4> b{a};  // I can copy element-wise from another std::array
                            // this is not possible with plain built-in arrays
  b = a;
  for (auto x : a) //x is the name of each element of a
    //he knows the size
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  a[0] = 0;  // same subscripting operator without bound checking
  //changing a I don't change b
  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (const auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto& x : a) //a reference defines an alias
    //x in this case is te very element of a
    x *= 10; //mult by 10 each element of a

  for (auto i = 0u; i < a.size(); ++i)
    std::cout << "a[" << i << "] = " << a[i] << std::endl;

  b.at(90);  // bound checking at run-time

  return 0;
}
