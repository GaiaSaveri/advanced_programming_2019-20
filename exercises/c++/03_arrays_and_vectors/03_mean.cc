#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

template<class T>
T vector_mean (std::vector<T> v) {
  T s{0}; //partial sums
  if (v.size() == 0)
    {std::cout<<"empty vector"<<std::endl;
      s=-1; }  
  else
    {
    for (int i=0u; i<v.size(); ++i)
	s += v.at(i); //at the end I have the sum of the elements of the vector
    if ( s==0 )
      std::cout<<"your vector contains only 0"<<std::endl;
       
    else if ( s != 0 )
      s=s/v.size(); //this is the mean
    }
  return s;}
    
template <class S>
S vector_median (std::vector<S> v) {
  S  m{0};
  std::sort(v.begin(), v.end()); //order the vector in ascending order
  if (v.size()%2 == 0) //vector has a even number of elements
    m=((v.at(v.size()-1)/2)+((v.at(v.size()-1)/2)+1))/2;
      //applying def of median for vector with even number of elements
  else if (v.size()%2 != 0)
    m=v.at(v.size()/2);
  return m;
}



      
int main () {
  std::ifstream temperature ("temperatures.txt");
  //temperatures contains 50 doubles in 50 lines
  if (temperature) //if yes, I store lines into a vector
    {std::vector<std::string> t; //initializing t
      std::string s;
      while (std::getline(temperature, s )){ 
	 //populating the vector  with lines of the file temperature
	t.push_back(s);}
      std::vector<double> temp; //here I put the temperatures
                                //after converting them in doubles
      for (int i=0u; i<t.size(); ++i) {
	double d=std::stod (t.at(i)); //converting every string to double
	temp.push_back(d);//pushing converted values to vector temp
      }
      
      double media=vector_mean(temp);
      std::cout<<"mean temperature is "<< media << std::endl;
      double mediana=vector_median(temp);
      std::cout<<"median temperature is: " << mediana << std::endl;
      
}
    
  else std::cout << "errore nel caricamento file";
      return 0;
}
