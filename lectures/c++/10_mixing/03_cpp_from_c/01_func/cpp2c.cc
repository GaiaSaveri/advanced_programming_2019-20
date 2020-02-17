#include <iostream>

extern "C" {
void hello_from_cpp() {
  std::cout << "hello from cpp\n";
}
}


/**voglio chimare in un main.c una funzione scritta in c++
   nel file dove scrivo la funzione in c++ 
   scrivo normalmente in c++, ma premettendo
   extern "C" dopo gli include
   compilazione:
   compilo separatamente il c e il cc normalmente
   e produco i due .o
   poi per produrre exe
   compilo il con il compilatore c e la flag -lstdc++
   cioè linko la standard library di c++ */

