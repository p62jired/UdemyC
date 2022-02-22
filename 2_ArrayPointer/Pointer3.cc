#include <iostream>
// &: Reference
// *p: De-reference

void printIntPointer(int *p)
{
    std::cout << "Value of the memory address p points:  " << *p << std::endl;
    std::cout << "Memory address of pointed value:  " << p << std::endl;
    std::cout << "Memory address of p: " << &p << std::endl;
}
void printDoublePointer(double *p)
{
    std::cout << "Value of the memory address p points:  " << *p << std::endl;
    std::cout << "Memory address of pointed value:  " << p << std::endl;
    std::cout << "Memory address of p: " << &p << std::endl;
}

int main()
{
    int a = 1337;
    double b = -13.37;
    int *c = &a;
    printIntPointer(c);
    //printDoublePointer(b);
    return 0;
}
