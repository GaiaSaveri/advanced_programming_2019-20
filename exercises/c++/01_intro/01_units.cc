#include <string>
#include <iostream>

int main(){
  std::string s;
  std::cout<<"insert measurment"<<std::endl;
  //solo esempio inch-metri
  std::cin>>s;
  //idea: se gli ultimi 4 caratteri della stringa sono "inch" devo convertire
  //altrimenti no
  std::string s1;
  if(s.length()<4) {
    std::cout<<"no way"<<std::endl;
    return 1;
  }
  s1= s.substr(s.length()-4);//estrae l'ultima parte
  if (s1 == "inch")//conversione necessaria
    {std::string s2 = s.erase(s.length()-5);
      //cancello sottostringa " inch" 
      //lavoro nell'ipotesi che quello che è rimasto sia un double
      //altrimenti posso usare funzione get_double dopo averla convertita
      //a funzione booleana e continuare solo se ritorna true
      double s21 = std::stod(s2);//converto string in double
      constexpr double conv_in_m=0.0254;
      s21 *=conv_in_m; //conversione
      std::cout<< s21 << "metri" <<std::endl;
    }
  else std::cout << "input not in inches!"<< std::endl;
  return 0;
}
