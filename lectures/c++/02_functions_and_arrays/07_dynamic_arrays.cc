#include <iostream>
//è possibile allocare gli array nello heap in modo dinamico
//usando un puntatore come identificativo e la parola chiave new
int main() {
  std::cout << "Please insert array lenght: ";
  std::size_t n;
  std::cin >> n;
  int* da{new int[n]};  // allocated on the HEAP, or free-store
  //Se si verifica un problema in fase di allocazione della memoria,
  //ad esempio se la dimensione dell’array è eccessiva,
  //il puntatore sarà nullo, pertanto è sempre opportuno verificare
  //il buon esito dell’operazione prima di accedere agli elementi dell’array.
  for (std::size_t i{0}; i < n; ++i)
    da[i] = i * 10;

  for (std::size_t i{0}; i < n; ++i)
    std::cout << "da[" << i << "] = " << da[i] << std::endl;
  //la deallocazione deve essere gestita dal programmatore
  //mediante l’operatore delete[]
  delete[] da;
  //uso delle parentesi quadre in questo caso è fondamentale per
  //la corretta deallocazione dell’intera area di memoria occupata dall’array
  return 0;
}
