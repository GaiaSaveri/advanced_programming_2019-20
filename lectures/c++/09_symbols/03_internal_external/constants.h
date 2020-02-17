#ifndef __constants__
#define __constants__

//how to handle global var?

//create global.h (header)
//if in the header we write 
//extern int circle_counter
//than the global var must be defined in a compilation unit
//than in the global.cc we can declare and define all the global vars

//than we include global.h in
//all the file in which we want to use global vars
//than there is no need to repeat anything
//but we need to link against global.cc
//global.cc is useful for the linker
//global.h is useful for the compiler


constexpr double pi{3.14159265358};
//if in front of a global symble we put the word "static"
//instead of const/constexpr
//it means internal linkage
//i.e. each computational unit has its own copy of the var

//moreover we can change the var of a static var
//change the value of a var who has internal linkage

//static=internal linkage

//if we change the value of pi in circle
//when we run the executable we see that greek has the 
//unchanged value of pi

//this is because the likage is internal
//so we need the external linkage
const double phi{1.6180339887};

//in c++, NOT in C, const implies internal linkage,
//i.e. it implies static

#endif


//constexpr we require that the computation is done at compile time
//with const this is not guaranteed
//arguments in templates must be marked as constexpr
//if the header is shared among c and c++ we have to write
//static const/constexpr 
//if we are sure that is only c++ we can forget static


//nm -C greek.o
//nm shows the symbols defined in a binary

//upper case means external linkage
//the other internal

//area_circle and golden_ratio have external linkage

//external linkage --> resolved at link time

//without -C we can see the name given by c++
//(no decripting, name mangling)
//and we see why overloading is possible
//function overloading is implemented changing the name of the symbols



//t is text
//r is read
//u is unit
