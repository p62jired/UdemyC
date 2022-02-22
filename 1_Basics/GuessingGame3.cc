#include <iostream>

//Prime Number: Only divisible by itself and 1 with a remainder of 0
int main()
{
    bool isPrimeNumber;
    unsigned short number = false;

    std::cout << "Give a number " << std::endl;
    std::cin >> number;
    for (unsigned short i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            isPrimeNumber = true;
        }
    }

    if (!isPrimeNumber)
    {
        std::cout << "Is not a prime number";
        return 0;
    }
    std::cout << "Is a prime number";
    return 0;
}
