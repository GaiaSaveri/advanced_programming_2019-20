#include<string>
#include<iostream>
#include<vector>

int main(){
  std::vector<int> primes{2};//dichiaro e inizializzo il vettore dei primi
  for(unsigned int i=3; i<100; ++i) {
    for (unsigned int j=2; j<i; ++j) {
      unsigned int reminder = i%j;
      if (reminder==0) break; 
      if (j==i-1 & reminder !=0) primes.push_back(i);
      else continue;}
     
  }
  for(int i=0u; i<primes.size(); ++i)
    std::cout << primes.at(i) << " ";
}      
      
  
