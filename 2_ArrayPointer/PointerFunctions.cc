#include <iostream>

//Call by value (local copy)
//Give the pointer value to a function. The value is copy local.
void f(int *p_function)
{
    std::cout << "(F): p_function  = " << p_function << std::endl;
    std::cout << "(F): &p_function  = " << &p_function << std::endl;
    std::cout << "(F): *p_function  = " << *p_function << std::endl;
}

//Call by Reference
void g(int *&p_function)
{
    std::cout << "(G): p_function  = " << p_function << std::endl;
    std::cout << "(G): &p_function  = " << &p_function << std::endl;
    std::cout << "(G): *p_function  = " << *p_function << std::endl;
}
int main()
{
    int *p_number = new int{4};
    std::cout << "(MAIN): p_number  = " << p_number << std::endl;
    std::cout << "(MAIN): &p_number  = " << &p_number << std::endl;

    f(p_number); //give value of p_number(address of other memory in Heap)
    g(p_number);
    return 0;
}
