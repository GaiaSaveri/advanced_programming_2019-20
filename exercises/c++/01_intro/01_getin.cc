#include <string>
#include <iostream>
void  get_int(){
std::string  i; //l'input può essere qualsiasi cosa
 while(std::cin >> i){
   for (int j =0; j<i.length(); ++j){
     if(i.at(j) < '0' || i.at(j) > '9')
       { std::cout << "not an integer!" << std::endl;
	 break;//appena trova qualcosa che non è un numero esce dal ciclo
   	std::cin.clear();
	std::cin.ignore();}
     else if ( j==i.length()-1) //sono alla fine della parola
                                //e tutto era intero
       { std::cout << "integer!!" << std::endl;
	 return;}
   }
  }
};

int main(){
  get_int();
  return 0;
}
