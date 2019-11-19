#include <array>
#include <iostream>
#include <vector>

struct Point_s {
  //private is the default visibility of the symbols
  //this is a difference with C struct
  //private:
  double x;
  double y;
  //public::
  void print();
};  // note ; at the end
//fully qualified name
void Point_s::print() {
  std::cout << "Structure. x = " << x << "; y = " << y << std::endl;
}

class Point_c {
  double x;
  double y;
  //private: accessible only from within other members of the same class
 public:
  //public:     accessible from anywhere where the object is visible
  void print() { //this function is defined inside this class
    std::cout << "Class. x = " << x << "; y = " << y << std::endl;
  }  // note no ; at the end
};   // note ; at the end

int main() {
  Point_s ps;
  //var of the struct are public!
  ps.x = 9.9;
  ps.y = 3. / 7;

  ps.print();

  Point_c pc;
  //interface of a class
  //class is the type
  //objects are istantiation of the class
  // pc.x =7.6; // error, x and y are by default private
  //cannot access from outside
  pc.print();  // I can access private data through public functions

  Point_s* p = &ps; //pointer to a struct
  //size of a struct is greateer or equal to the size of each element
  //size of pointer is always 64bits, it is convenient to pass a pointer
  //A pointer to a struct can be cast to a pointer to its first member
  p->x = 0.0;
  //p now points to the struct
  //arrow operator: used with a POINTER VARIABLE 
  //pointing to a structure
  //allows to access elements in structures
  p->print();

  //once you have a type you can have a reference to that type
  //and auto works
  auto& pr = ps; //pr is a reference to ps, alias to ps
  ++pr.x; //incrementing by 1 the x member of ps
  pr.print(); //same as ps.print

  Point_s array_of_structs[8];  // built-in array
  array_of_structs[0].x = 1; //each element of the array is a point
  array_of_structs[0].y = 2;

  std::array<Point_s, 5> as;
  as[3].x = 3;

  std::vector<Point_s> vs;
  vs.push_back(ps);
  //vs and ps are different objects
  vs[0].x = 999;
  ps.x = 11;
  ps.print();
  vs[0].print();

  return 0;
}
