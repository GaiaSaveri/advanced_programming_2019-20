#include "class_c_interface.h"
#include <stdio.h>

int main() {
  Foo_c f = create_foo(11);
  print_foo(f);
  set_a(f, 7);
  print_foo(f);
  set_a(f, 9);
  printf("hello from c! a is %d\n", get_a(f));
  free_foo(f);
  return 0;
}

/** i file .hpp e .cpp sono normali interfaccia e implementazione
    di una classe in c+
    nell'interfaccia .h in c devo dichiarare un 
    typedef void * con il nome della classe
    perché in c non ci sono classi
    e tutte le dichiarazioni delle funzioni dentro a un extern "C"
    nell'implementazione devo implementare le funzioni in un cpp
    traducendole in C dentro un extern "C"
    tipo ctor e dtor vanno scritti in C
    e tutti i cast devono essere espiliciti static_cast<c++class*> 
    compilazione:
    produco tutti i .o con i rispettivi compilatori
    poi per compilare il main in c linko stdc++
    
   */
