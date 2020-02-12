#include<array>
#include<iostream>
#include<utility>
#include<string>

template<std::size_t N>
void print_matrix(std::array<double, N> &mat, int row, int col) {
    for (int i=0u; i<row; ++i) {
    for (int j=0u; j<col; ++j) {
      std::cout << mat[i*col+j] << " ";
    }
    std::cout << std::endl;
  }
}

template <std::size_t N>
std::array<double, N>  transpose (std::array<double, N> &mat, int row, int col)
{  std::array<double, mat.size()> tra; //array where the transpose is stored
  for (int i=0u; i<row; ++i ){
    for (int j=0u; j<col; ++j) {
      std::swap (mat[i*col+j], tra[j*row+i]);
    }
  }
  return tra;
}


int main(int argc, char* argv[]){
  std::cout<<"number of rows is: " << argv[1] << std::endl;
  std::cout<<"number of columns is: " << argv[2] << std::endl;
 
  //arguments in argv are strings, need to cast to int: use std::stoi
  int row{std::stoi(argv[1])};
  int col{std::stoi(argv[2])};
  const int N{12}; //number of elements
  std::array<double, N> mat; //array where the matrix is stored
  for (int i=0u; i<row; ++i){//takes care of rows
    for (int j=0u; j<col; ++j) { //takes care of columns
      std::cout<<"please insert element [" <<i<<"]["<<j<<"] ";
      std::cin>>mat[i*col+j]; //populating the matrix from stdin
    }
  }
  std::cout << "matrix is: "<<std::endl;
  print_matrix(mat, row, col);
  
  std::array<double, N> tra;
  mat=transpose(mat, row, col);
  
  std::cout << "transpose matrix is: "<<std::endl;
  print_matrix(mat, col, row);
  return 0;
}
      
