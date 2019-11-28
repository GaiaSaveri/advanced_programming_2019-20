#include "ap_error.h"
#include <iostream>

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(weight >= 0) << "invalid weight: " << weight << std::endl;
  }

  Animal() noexcept : Animal{0, 0} {}  // delegating constructor

  void speak() const noexcept { std::cout << "Unknown\n"; }
  void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }
};

struct Dog : public Animal {//here : represents "is a" (public)
  //with this dog will have the attributes of animal
  //size of the children is always equal or larger to the parent's class
  //public: visible from outside
  //dog can access all and only public members of animals

  //protected: from outside is like private
  //but children can access protected vars
  //with protected I can change inside dog private members of animal
  //but can't do that e.g. from the main

  //private, protected, inheritance: implement the concept of "usa a"
  //for example std::vector inherites private from another class
  //allocation and deallocation
  //but this is an implementation detail

  
  void speak() const noexcept { std::cout << "Bau\n"; }
  Dog() noexcept = default;
  //delegating constructor
  //inside the constructor I use the parent's constructor
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
  //function info is not implemented
  //because it is public in animal
};

struct Snake : public Animal {
  bool dangerous;
  //construction is from top to bottom
  //first construct the parent with a delegated constructor
  //then initilizes the child's own members
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) noexcept : Animal{}, dangerous{b} {}
  void info() const noexcept {
    //to refer to info function of the function
    //we need to use the fully qualified name
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept { std::cout << "ssss\n"; }
};

// run-time (dynamic) polymorphism
//here dog and snake can be passed as argument
//with run-time poly we can pass a children (reference and pointer, no value)
//to a function that expects the parent
void print_animal(const Animal& a) noexcept {
  std::cout << "through ref\n";
  a.info();
  a.speak();
}

// compile-time (static) polymorphism (=template)
//all types must be known at compile time
template <class T>
void print_animal_template(const T& a) noexcept {
  std::cout << "through template\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Dog d;
    d.info();
    d.speak();

    std::cout << std::endl;

    Dog d1{0, 0.6};
    d1.info();
    d1.speak();

    std::cout << std::endl;

    Snake s{true};
    s.info();
    s.speak();

    std::cout << std::endl;

    Animal* p = new Snake{1, 2.3, false}; //runtime poly
    //a pointer to a base class can point to all of the children
    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    std::cout << std::endl;

    print_animal(s);

    std::cout << std::endl;

    print_animal_template(s); //type is resolved at compile time

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
//in this example runtime poly is wrong
//while the template works
