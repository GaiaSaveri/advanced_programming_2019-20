#include <iostream>
#include <memory>  // std::uniqe_ptr

#include "ap_error.h"

//shared pointer need to know how many are using this pointer
//slower than oher pointers
class Vector {//no more raw pointer
  std::unique_ptr<double[]> elem;

 public:
  Vector(const unsigned int l) : elem{new double[l]} {
    std::cout << "Vector ctor\n";
  }
  double& operator[](const unsigned int i) noexcept {
    return elem[i];
  }  // you can use smart pointers almost like raw pointers
  ~Vector() noexcept { std::cout << "~Vector\n"; }
};

class ManyResources {
  std::unique_ptr<double[]> ptr;
  Vector v;
  //unique pointer as well
  //it is important not to have more than one unique ptr
  //pointing to the same thing
 public:
  ManyResources() : ptr{new double[5]}, v{3} {
    std::cout << "ManyResources ctor\n";
    AP_ERROR(false) << "I am simulating something wrong.\n";
  }
  ~ManyResources() noexcept { std::cout << "~ManyResources\n"; }
};

int main() {
  try {
    std::unique_ptr<int[]> up{new int[7]};
    ManyResources mr;

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;

  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n" << std::endl;
    return 2;
  }

  return 0;
}
