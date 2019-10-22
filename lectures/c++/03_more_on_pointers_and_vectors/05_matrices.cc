#include <iomanip>
#include <iostream>

void print_ma(int m[][5], int dim1);
//the size of the columns must be known to pass a matrix
//as argument of a function
// ugly and not flexible
// void print_ma(int m[][], int dim1, int dim2); // error second
// dimension must be
// knwon at compile time

void print_ma(int* p, int row, int col);  // the only possible solution

int main() {
  int ma[6][5];  // matrix: 6 rows, 5 columns each in the stack
  //this is the most readable way to define a matrix
  //not usable when we want to allocate in the heap
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 5; ++j)
      ma[i][j] = 10 * i + j;//way to access the matrix

  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << std::setw(3) << ma[i][j];
    std::cout << std::endl;
  }
  //print addresses to see how it is in the memory
  //actually they are continuous
  //a matrix is stored as a long array 
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j)
      std::cout << &ma[i][j] << " ";
    std::cout << std::endl;
  }

  // int *pma {ma}; 		// error
  // int *pma[5] {ma};		// error
  int* p{reinterpret_cast<int*>(ma)};
  //necessary to pass a matrix as argument
  //with the other declaration it is not necessary
  // int* p {&ma[0][0]};

  // print_ma(ma, 6, 5); 	// error
  print_ma(p, 6, 5);

  auto d_ma = new int[6 * 5]{}; //allocation of a matrix on the heap
  //array of 30 elements

  std::cout << std::endl;

  print_ma(d_ma, 6, 5);
  delete[] d_ma;

  return 0;
}
//c++ is row-wise
//in memory rows are allined
//1 stelement of the second row is the...
void print_ma(int* p, int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j)
      std::cout << std::setw(2) << p[i * col + j] << " ";
    std::cout << std::endl;
  }
}
