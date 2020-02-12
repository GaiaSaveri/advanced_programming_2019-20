#include <string>
#include <iostream>

int main(){
  std::string line;
  int n{0}; //contatore per stringhe
   std::string s1; //stringa appena inserita
   std::string s2; //stringa iterazione precedente
   //dato che n è inizializzato a 0
   //alla prima iterazione voglio s1 == s2
   
  while(std::getline(std::cin,line))
    { s1 = line; //la stringa appena inserita}

        if(s1==s2 & n != 0)
	  n +=1; //se la stringa corrente e la precedente sono uguali
                 //aggiorno il contatore
        if (s1 != s2 & n !=0)
	  {std::cout << "     " << n << s2 << std::endl;
	 //se la stringa corrente è diversa
	//dalla precedente, stampo la precente con numero ripetizioni
	    n = 1; //aggiorno il contatore
	  }
	 if(n==0) //ovvero sono alla prima iterazione
	    n +=1; //aggiorno solo il contatore
	s2 = s1; //metto la stringa corrente nella variabile s2
      
    }
}
