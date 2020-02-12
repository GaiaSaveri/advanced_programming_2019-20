#include <string>
#include <iostream>

int main() {
  int* prime{new int[1]}; //array dove metterò i numeri primi
  //sta puntando la prima cella dell'array
  //ogni volta che trovo un primo aumento la dimensione dell'array
  prime[0]==2;
  unsigned int c{1}; //conta il numero di primi trovati
  for (int i=3; i<100; ++i)
    {for (int j=2; j<i; ++j)
	{unsigned int reminder = i%j;
	  if (reminder == 0) break; //non è un numero primo
	  if (reminder != 0 & j != i-1) continue; //non sono all'ultimo ciclo
	  if (reminder != 0 & j == i-1) //ho trovato un primo
	    {
	      c++; //incremento contatore
	      int* exp_prime{new int[c]}; //array con la nuova dimensione
	      for (unsigned int w=0; w<c; ++w)
		{ exp_prime[w]=prime[w]; }//copio il vecchio nel nuovo
		  exp_prime[c-1]=i; //nell'ultima cella metto il num primo
	      delete[] prime;
	      prime = exp_prime;
	    }
	}
    }
  for (unsigned int i=0; i<c; ++i)
    std::cout << prime[i]<< ' ';
  delete[] prime;
}
  
  
	      
	    
  
