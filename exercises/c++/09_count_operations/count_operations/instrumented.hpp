// adapted from Alexander Stepanov: Efficient Programming with Components

#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H
#include <algorithm>
#include <utility>

struct instrumented_base {
  enum operations { //enum is to generate constant
		    //enum inside a class do not occupy space
		    //enums start from 0!
 
    n,
    copy_ctor,
    copy_assign,
    move_ctor,
    move_assign,
    default_ctor,
    dtor,
    equality,
    comparison
  };

  //keyword static in this context means that
  //var that is shared among all the instantiation of the same class
  
  
  //a class that have static var
  //they are outside the class

  
  static constexpr std::size_t n_ops = 9;
  static double counts[n_ops];
  static const char* counter_names[n_ops]; //actually array of string
  //string allocate things on the heap
  //like an std::vector of char
  //we don't want to slow down the code so we use this
  static void initialize(std::size_t i) {
    std::fill(counts, counts + n_ops, 0.0);
    counts[n] = i;
  }
  static void print_summary(); //static bc shared among all the objects
  static void print_header();
};

//static functions has to be defined in a cpp file
//(or any compilation extention)
//instrumented.cpp

template <typename T>
// T is Semiregualr or Regular or TotallyOrdered
struct instrumented : instrumented_base {
  using base = instrumented_base;
  typedef T value_type;
  T value;
  // Conversions from T and to T:
  instrumented(const T& x) : value(x) {}
  explicit operator T() const { return value; }
  //since instrumented_base is not templated
  //both instr_int and double will inherite from the same class

  
  //ctors define explicit rule for conversion
  template <typename U>
  instrumented(const instrumented<U>& x) : value(x.value) {}

  // Semiregular:
  //default ctor, dtor, copy and move semantic
  instrumented(const instrumented& x) : value(x.value) { ++counts[copy_ctor]; }
  instrumented(instrumented&& x) : value{std::move(x)} { ++counts[move_ctor]; }
  instrumented() { ++counts[default_ctor]; }
  ~instrumented() { ++counts[dtor]; }

  //keeping track of all the operations
  
  instrumented& operator=(const instrumented& x) {
    ++counts[copy_assign];
    value = x.value;
    return *this;
  }

  instrumented& operator=(instrumented&& x) {
    ++counts[move_assign];
    value = std::move(x.value);
    return *this;
  }

  // Regular
  //an object is regular if it has the overload of ==
  //and != (that is the negation off ==)
  friend bool operator==(const instrumented& x, const instrumented& y) {
    ++counts[equality];
    return x.value == y.value;
  }
  friend bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }
  // TotallyOrdered
  //it has defined the < operator
  //all the other comparison operator comes for free
  friend bool operator<(const instrumented& x, const instrumented& y) {
    ++counts[comparison];
    return x.value < y.value;
  }
  friend bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }
  friend bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }
  friend bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  }

  // needed by std::iota
  instrumented& operator++() {
    ++value;
    return *this;
  }
};

#endif
