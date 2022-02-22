#include <iostream>
// Leep Year :
//divisible by 4
//if divisible by 100, then only a leap year if its divisible by 400
int main()
{
    int year;
    std::cout << "Please enter your number: ";
    std::cin >> year;

    if (!(year % 4 == 0))
    {
        std::cout << "It is not a leap year";
        return 0;
    }
    if (!((year % 100 == 0) && (year % 400 == 0)))
    {
        std::cout << "It is not a leap year";
        return 0;
    }
    std::cout << "It is a leap year";
    return 0;
}
