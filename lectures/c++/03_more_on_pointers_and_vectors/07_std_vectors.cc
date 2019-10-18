#include <iostream>
#include <string>
#include <vector>

// template<class T, class Allocator = std::allocator<T>>
// class vector;
//usully we define vectors we don't put the 2nd argument

template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s);

int main() {
  //std::vectors stores in the heap
  std::vector<int> v0{1, 2, 4};//3 elements: 1,2,4
  std::vector<int> v1(4, 4);//4 elements that are all 4

  print_vector(v0, "v0");
  print_vector(v1, "v1");

  v1 = v0;//copy elementwise the vector
  //std::vectors are flexible
  //after this the size of v1 is 3

  print_vector(v1, "v1 after copy");

  for (auto x : {7, 8, 9})
    v1.push_back(x);//expand dinamically the vector, adding one element at time
  //dinamically resized to fit the new size
  print_vector(v1, "v1 after push_back");

  for (auto i = 0u; i < v1.size(); ++i)
    std::cout << "v[" << i << "] = " << v1[i] << std::endl;

  std::cout << v1[3] << " " << v1[78] << std::endl;        // no bounds checking
  std::cout << v1.at(3) << " " << v1.at(78) << std::endl;  // bounds checking

  //memory is automatically deallocated
  //way better than build in array
  return 0;
}

template <typename T>
//std::vector can be passed by reference
//no need to pass the pointer to the first element
void print_vector(const std::vector<T>& v, const std::string& s) {
  std::cout << s << ": ";
  for (const auto& x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}

//a reference can be seen as a pointer dereferencing to itself
//kind of const pointer
//for referefernces moreover there is no such a thing as nullptr
