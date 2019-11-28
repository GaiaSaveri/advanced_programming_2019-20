#include <iostream>

template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};
//compile error if we omitt this
//this is a pointer to myself

//if the base is templated-->use this
//pointer to a class: arrow operator
template <typename T>
struct Derived : public Base<T> {
  void bar() const { this->foo(); }
};

int main() {
  Derived<int> d;
  d.bar();
}
