#include <string>
#include <iostream>

//un double ha solo cifre intere e eventualmente uno e un solo punto

void get_double(){
  std::string i;
  int n; //conta i '.'
  while(std::cin>>i){
    n=0; //per ogni parola inizializzo il contatore dei punti
    for(int j=0; j<i.length(); ++j){
      if( j!=0 & i.at(j)=='.'& n!=0)//è già stato digitato un punto
	{std::cout << "not a double" << std::endl;
	 std::cin.clear();
	 std::cin.ignore();
	 break;}
      else if (j==0 & i.at(j)=='.')//il primo carattere non può essere il punto
	{std::cout << "not a double" << std::endl;
	 std::cin.clear();
	 std::cin.ignore();
	 break;}
      else if (j!=0 & i.at(j)=='.' & n==0)
	{n += 1;} //trovato il punto aggiorno il contatore
      //oltre al punto, tutte le altre entrate devono essere interi
      else if (i.at(j) < '0' || i.at(j) > '9') //stessa condizione di getint
	{std::cout << "not a double" << std::endl;
	 std::cin.clear();
	 std::cin.ignore();
	 break;}
      if (j==i.length()-1) //sono all'ultimo carattere e non è entrato
	                   //in nessuna ocndizione precedente
	{std::cout<<"finally!"<<std::endl;
	  return;}//appena trovo un double esco dalla funzione
    }
  }
};

int main() {
  get_double();
  return 0;
}
