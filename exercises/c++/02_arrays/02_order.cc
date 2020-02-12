#include <iostream>
#include <string>

template <typename  T>
//the function returns the pointer to the first element
//of the array
//the argument of the function is the size of the array
T* arr_point(std::size_t n) {
  T* ain{new T[n]}; //allocato array nello heap
  std::cout << "please insert array elements: " << std::endl;
  for (int i{0}; i<n; ++i)
     std::cin >> ain[i];
 //ok inizializzazione array da stdin
  std::cout<<std::endl;
  return ain;//puntatore al primo elemento dell'array
}


template <typename T>
void reverse(T* a, std::size_t n)
{
  for(int i=0; i<n; ++i)
    std::cout << a[n-i-1] << " "; //dall'ultimo al primo
  std::cout<<std::endl;

}
      



int main() {
  std::cout << "please insert array dimension: " << std::endl;
  std::size_t n;
  std::cin>>n;
  std::string s;
  std::string i{"i"};
  std::string d{"d"};
  std::cout<<"Do you want to insert an array of double (tape d) or int (tape i)?"<<std::endl;
   std::cin>>s;
   if(s==i) {
     std::cout<<"array of ints"<<std::endl;
     int* aint=arr_point<int>(n);
     std::cout<<"reverse array is: " << std::endl;
     reverse(aint, n);
     delete[] aint;
   }
   else if(s==d) {
     std::cout<<"array of doubles"<<std::endl;
     double* adou=arr_point<double>(n);
     std::cout<<"reverse array is: "  << std::endl;
     reverse(adou, n);
     delete[] adou;
   }
   else std::cout<<"wrong type specified"<<std::endl;
   return 0;
}


