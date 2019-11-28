#include <ap_error.h>
#include <iostream>

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(!(weight < 0)) << "invalid weight!\n";
  }

  Animal() : Animal{0, 0} {}  // delegating constructor
  
  //function that should be reimplemented by the children
  //should be marked as virtual 
  virtual void speak() const = 0;  // pure virtual function ==> abstract class
  //=0 means that function is pure virtual
  //animal is an abstract class
  //cannot instanciate an object of an abstract class
  //an abstract class is a class with at least one pure viruaò function

  //when you inherit you inherit data and interface
  //fixing the interface is one of the reasons to use inheritance
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
    //throughv the keyword virtual the compiler inserts a pointer
    //in the virtual table
  }

  virtual ~Animal() {}  // why? see file 03_virtual_destructor.cc
};

struct Dog : public Animal {
  void speak() const noexcept override { std::cout << "Bau\n"; }
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

//empty struct has 1 byte bc we cannot allocate things in the same address
//so it is not 0 to prevent this
//size of an object is the size of its class

//if I have a only a virtual function on a struct
//the size of the struct is 8, size of the pointer

//compiler has a virtual table
//each time a children is generated there is line added to that table
//and that line contains a pointer to the virtual function

//function cannot be inlined, doing a function is a jump
//also going from the pointer to the function to the actual addres
//of the function is a jump

//it is not good to have a function that is called many times virtual
//jumps kill the performance


struct Snake : public Animal {
  bool dangerous;
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) : Animal{}, dangerous{b} {}
  void info() const noexcept override {
    //all these keywords are poistional
    //override is from c++11 (as is noexcept)
    //with override the compile double check if there is a function
    //in the parent's class sema nae, same parameters, virtual
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

void print_animal(const Animal& a) noexcept {
  std::cout << "throught ref\n";
  //override is with virtual
  //overload is same name different parameters
  a.info();
  a.speak();
}

int main() {
  try {
    Snake s{true};
    s.info();
    s.speak();

    std::cout << std::endl;

    Animal* p = new Snake{1, 2.3, false};

    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    std::cout << std::endl;

    print_animal(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
