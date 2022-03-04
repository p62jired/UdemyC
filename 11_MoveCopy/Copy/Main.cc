#include <cstddef>
#include <iostream>

#include "AlgoArray.h"
#include "DynArray.h"

// int main()
int main()
{
    DynamicArray<double> a1(1.0, 3);
    DynamicArray<double> a2(-1.0, 4);
    DynamicArray<double> a3 = a2;   //Copy constructor
    DynamicArray<double> a4(a2);    //Copy constructor
    DynamicArray<double> a5{a2};    //Copy constructor
    DynamicArray<double> a6 = {a2}; //Copy constructor

    a1 = a2; //Copy assignment operator
    return 0;
}
