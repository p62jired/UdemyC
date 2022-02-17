#include <iostream>
// &: Reference
// *p: De-reference

int main()
{
    // Heap allocation
    int *p = new int;
    *p = 4;
    // std::cout << "Memory address of p: " << &p << std::endl;
    // std::cout << "Memory address of pointed value:  " << p << std::endl;
    // std::cout << "Value of the memory address p points:  " << *p << std::endl;

    // *p = 1500;
    // std::cout << "Memory address of p: " << &p << std::endl;
    // std::cout << "Memory address of pointed value:  " << p << std::endl;
    // std::cout << "Value of the memory address p points:  " << *p << std::endl;

    //Heap dealocation
    delete p;
    std::cout << "Memory address of pointed value:  " << p << std::endl;
    p = nullptr;
    std::cout << "Memory address of pointed value:  " << p << std::endl;
    //crontrol if pointer var is used
    if (p != nullptr)
    {
        std::cout << *p << std::endl;
    }

    return 0;
}
