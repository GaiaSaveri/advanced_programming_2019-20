extern "C" {
#include "hello.h"
}

int main() {
  hello_from_c();
  return 0;
}

/** per eseguire in un main.cc una funzione scritta in c
    faccio header e .c normalmente in c
    metto dentro extern "C" l'header scritta in c
    compilo separatamente i due .o
    linko per produrre l'exe senza flag 
    */
    
