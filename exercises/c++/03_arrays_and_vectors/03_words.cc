#include<vector>
#include<string>
#include<iostream>

int main() {
std::vector<std::string> words;
 std::string parola;
 std::cout<<"Insert words"<<std::endl;
while (std::cin>>parola)
words.push_back(parola);
 for (int i=0u; i<words.size()-1; ++i)
 //no need to compare last word with the others
{for (int j=i+1; j<words.size(); ++j)
{if (words.at(i)==words.at(j)) 
{words.erase(words.begin()+(j));
  --j;} //deleting the repeted element
//since if we delete elements indeces rescale
}
}
for (int i=0u; i<words.size(); ++i)
std::cout<<words.at(i)<<" ";
std::cout<<std::endl;
}
