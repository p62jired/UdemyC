#include <iomanip>
#include <iostream>
// 1a. C++: static_cast<newDtype>(varName) - converts object from one type to another
// 1b. C: (newDtytpe)(varName)
int main()
{
    double number = 3.13;
    std::cout << std::setprecision(30) << number << std::endl;
    int number2 = number;
    std::cout << number2 << std::endl;

    //C++ Casting:
    float number5 = static_cast<float>(number);
    std::cout << std::setprecision(30) << number5 << std::endl;
    return 0;
}
