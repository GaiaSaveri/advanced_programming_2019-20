#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  //constructor that takes the size of the vector
  Vector(const std::size_t size) : elem{new num[size]}, _size{size}
  {//body is empty but we have to put the body
  }
  //elem store the address
  
  //RAII Resource Aquisition Is Initialization
  //resourced has been acquired at construction time
  //release in the destructor

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  //const means that the state of my object will not be changed
  //if I run this function
  std::size_t size() const { return _size; }

  num& operator[](const std::size_t i) { return elem[i]; }
  //built in array

  // try to comment this line and recompile
  //kind of overloading
  const num& operator[](const std::size_t i) const { return elem[i]; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}
//v[i] is the overload operator
//the compile double check that we don't modify const things
//with custom type

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name using arrow

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555;

  std::cout << v << std::endl;

  return 0;
}
