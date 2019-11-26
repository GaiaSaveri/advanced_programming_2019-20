#include <algorithm>  // std::copy
#include <iostream>
#include <memory>

template <typename T>
class Vector {
  std::size_t _size;
  std::unique_ptr<T[]> elem; //avoid to delete manually

 public:
  // custom ctor
  explicit Vector(const std::size_t length)
      : _size{length}, elem{new T[length]{}} {
    std::cout << "custom ctor\n";
  }

  // Vector(const std::initializer_list<T> args)
  //     : _size{args.size()}, elem{new T[_size]} {
  //   std::cout << "list ctor\n";
  //   std::copy(args.begin(), args.end(), begin());
  // }

  // default ctor --> the one that takes no argument
  Vector() { std::cout << "default ctor\n"; }  // _size uninitialized
  // Vector() : _size{}, elem{} { std::cout << "default ctor\n"; } // this could
  // be better Vector() = default;

  ~Vector() = default;

  /////////////////////////
  // copy semantics

  // copy ctor -- deep copy
  Vector(const Vector& v); //takes a const reference of the same type

  // copy assignment -- deep copy
  Vector& operator=(const Vector& v); //overload of the operator =
  // end of copy semantics
  /////////////////////////

  /////////////////////////
  // move semantics
//we are a vector and we want to refer to the elements of another 
//vector without any copy
  // move ctor
  //the compiler does a move elementwise
  //with row pointer, built in type, this is not fine
  Vector(Vector&& v) : _size{std::move(v._size)}, elem{std::move(v.elem)} {
    std::cout << "move ctor\n";
  }
//goal is to move v to the current vector-->after move v is empty
  //want to swap two objects, without creating a third object
  //this is done by moving semantic
  //most efficient implementation of swap

  //just one & --> l value reference : var that can stay both on lhs and rhs
  //of an = sign

  //two && --> can stay only on the rhs of the = sign
  
  // Vector(Vector&& v) = default; // ok

  //think the move as a swap


 //la move semantics consente di evitare copie non necessarie quando
//si lavora con oggetti temporanei


// move assignment
  //move assignment in all the elements (on each element)
  Vector& operator=(Vector&& v) {
    std::cout << "move assignment\n";
    _size = std::move(v._size);
    elem = std::move(v.elem);
    return *this; //this is a pointer to ourselves
  }

  // Vector& operator=(Vector&& v) = default; // ok

  // end move semantics
  /////////////////////////

  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }

  // range-for
  const T* begin() const { return &elem[0]; }
  T* begin() { return &elem[0]; }

  const T* end() const { return &elem[_size]; }
  T* end() { return &elem[_size]; }
};

// copy ctor --> take as argument the object from which to copy
template <typename T>
Vector<T>::Vector(const Vector& v) : _size{v._size}, elem{new T[_size]} {
  std::cout << "copy ctor\n";
  std::copy(v.begin(), v.end(), begin());
//copies from v.begin() to v.end() 
//(last element copied is v.end()-1)
//the copy starts at begin()
}

// copy assignment
//we are implementing the copy constructor,
//we want to copy elmentwise

//NOTE: can acces private member of vector
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v) {
  std::cout << "copy assignment (\n";

  // we could decide that this operation is allowed if and only if
  // _size == v._size
  //

  elem.reset();              // first of all clean my memory
//so now elem is empty --> deallocating the old space
  //reset is a function of the unique pointer
//that destroys the object currently managed by the unique pointer
  auto tmp = v;  //here in tmp we make a copy of v     
//the pointer "this" points to the object
//the member function was called  
 (*this) = std::move(tmp);  // finally move assignment
//in this case "this" points to a unique ptr
//so *this is a unique pointer
//with std::move the property of "this", namely *this, 
//is given to tmp
//now we are pointing to the new elements
  //overload of operators works with objects not pointers

  // or we do everything by hand..
  // and we can do not reset and call new again if the sizes are suitable

  std::cout << ")\n";
  return *this;

  // is this approach consistent with self-assignment vx=vx?
}

template <typename T>
//overload of the operator +
// why we return by value?
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs) {
  const auto size = lhs.size();

  // how we should check that the two vectors have the same size?

  Vector<T> res(size); //new vector
  for (std::size_t i = 0; i < size; ++i)
    res[i] = lhs[i] + rhs[i];

  return res; //I can only return this result by value
  //a reference is a kind of pointer that automaticall dereferences itself
  //if we want to return the pointer we have to allocate it on the heap
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (const auto& x : v)
    os << x << " ";
  os << std::endl;
  return os;
}

int main() {
  std::cout << "Vector<int> v0; calls\n";
  Vector<int> v0;
  std::cout << v0.size() << "\n";
  std::cout << "Vector<int> v00{}; calls\n";
  Vector<int> v00{};
  std::cout << v00.size() << "\n";

  std::cout << "\nVector<double> v1{5}; calls\n";
  Vector<double> v1{5};

  std::cout << "\nVector<double> v2 = v1; calls\n";
  Vector<double> v2 = v1;
  std::cout << "\nv2 = Vector<double>{7}; calls\n";
  v2 = Vector<double>{7};
  std::cout << "\nVector<double> v3{std::move(v1)}; calls\n";
  Vector<double> v3{std::move(v1)};  // now v1 should not be used
  std::cout << "\nv3 = v2; calls\n";
  v3 = v2;
  std::cout << "\nv2 = " << v2;
  std::cout << "v3 = " << v3;

  std::cout << "\nassign some values to v3\n";
  {
    // auto i = v3.size();
    // while (i--)
    //   v3[i] = i;

    int c = 0;
    for (auto& x : v3)
      x = c++;
  }
  // v3=v3;
  std::cout << "\nv2 = " << v2;
  std::cout << "v3 = " << v3;

  std::cout << "\nVector<double> v4{v3 + v3}; calls\n";
  Vector<double> v4{v3 + v3};

  std::cout << "v4 = " << v4;

  std::cout << "\nNRVO: Named Return Value Optimization\n";

  std::cout << "\nv4 = v3 + v3 + v2 + v3; calls\n";
  v4 = v3 + v3 + v2 + v3;
  std::cout << "v4 = " << v4;

  return 0;
}
