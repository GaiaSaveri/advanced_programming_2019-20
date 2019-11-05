#include <iostream>

//copy comstructor + copy assignment = copy semantic

template <typename T>
class Vector {
  T* elem; //pointer to what will be the real array
  std::size_t _size; 
  //type --> particular impementation of a concept
 public:
  //explicit?
  explicit Vector(const std::size_t length)
      : elem{new T[length]{}}, _size{length} {}
  //T length is array of type T and length "length"
  //with {} it is inizialized

  ~Vector() { delete[] elem; } //destruptor
  //overload of the operator [] with and without const
  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }

  // range-for (since c++11)

  //need to define function begin and function end
  
  const T* begin() const { return elem; }
  T* begin() { return elem; } //returns a pointer to the first element

  const T* end() const { return elem + size(); }
  T* end() { return elem + size(); } //returns a pointer to last element
};

//remove explicit
//void print(const Vector<int>& v) {
//  for (auto x:v)
//    std::cout<<x<<std::endl; }

//inside the main write print(v1) --> compiles and print 1 2 3
//then write print(1) --> expect a vector, not an integer
//compiles and implicitely invoke the constructor of this type
//and converts the input

//putting explicit we avoid this kind of things

int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

 
  //{ auto it = v1.begin(); pointer to the first element
  //  auto stop = v1.end();
  //for(; it!=stop; ++it) //iterate until pointer points to last element
                          //stop must be one past the last
                          //see how iterations work!
  // { const auto x = *it; }
  std::cout << "v1: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;
  //try to copy v1 into v2
  Vector<int> v2{v1};  // default copy constructor

  std::cout << "v2 after default copy ctor: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}

//a compiler can just copy by value each member
//v2.elem same value v1.elem
//same portion of memory pointed to by two pointers
//same region of memory is deleted by to destruptor (double free compiler error)
//shallow copy: cheap, copies only a pointer --> RAII doesn't work
//take home message: better to copy by value
