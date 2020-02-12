#include <iostream>
#include <memory>

//since c++11 we have smart pointers

template <typename T>
class Vector {
//unique pointer to an array, can't have memory leaks with unique pointers
//smart pointer that owns and manages another object through a 
//pointer and disposes of that object 
//when the unique_ptr goes out of scope
//deleted when the object pointed by is destroyed
//or when the object is assigned to another pointer
//Only non-const unique_ptr can transfer the ownership of the 
//managed object to another unique_ptr
  //put delete keyword in copy constructor and copy assignment
  //get --> arrow pointer (normal pointer) pointed to by them
  //release --> need to remember to delete at the end
//release: releases the ownership of the managed object if any
  //reset
  std::unique_ptr<T[]> elem;//implementation of the concept of ownership
  std::size_t _size;

 public:
  explicit Vector(const std::size_t length)
      : elem{new T[length]{}}, _size{length} {}

  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }

  // range-for
  const T* begin() const { return elem.get(); }
  T* begin() { return elem.get(); }

  const T* end() const { return elem.get() + _size; }
  T* end() { return elem.get() + _size; }
};

int main() {
  Vector<double> v1{7};
  // Vector<double> v2{v1}; // default copy ctor calls a deleted function by
  // std::unique_ptr //the compiler tells "use of deleted function"
  return 0;
}
