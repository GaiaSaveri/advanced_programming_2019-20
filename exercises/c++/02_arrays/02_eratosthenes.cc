#include<cmath> //sqrt
#include<iostream>

int main() { 
  int N;
  std::cout<<"Please insert integer number: "<<std::endl;
  std::cin>>N;
  int l[N-1];
  bool b[N-1];
  //populate the arrays
  //l with integers 2..N
  //b with all true
  for(int i=0; i<N-1; ++i)
    { l[i]=i+2;
      b[i]=true;
    }

  for(int i=0; i<=static_cast<int>(std::sqrt(N))-2; ++i) {
    if(b[i]==true) {
      for(int j=l[i]*l[i]; j<=N; j=j+l[i])
	  b[j-2]=false;
    }
  }
  for(int i=0; i<N-1; ++i) {
    if(b[i]==true)
      std::cout<<l[i]<<std::endl;
  }
  return 0;
}
