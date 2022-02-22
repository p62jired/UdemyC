#include <iostream>

int main()
{
    int number;
    std::cout << "Please enter your number: ";
    std::cin >> number;
    double absolute;
    if (number < 0)
    {
        absolute = (-1) * number;
    }
    else
    {
        absolute = number;
    }
    std::cout << "The absolute value is: " << absolute << std::endl;
    return 0;
}
