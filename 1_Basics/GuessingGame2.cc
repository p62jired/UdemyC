#include <iostream>
void foo()
{
    int number;
    std::cout << "Please enter your number: ";
    std::cin >> number;
    if (!(number >= 0 && number <= 10))
    {
        std::cout << "Number not in rage 0-10" << std::endl;
        return;
    }
    if (number % 2 == 0) //rest division is equal  0
    {
        std::cout << "You won the Spoon" << std::endl;
        return;
    }
    if (number != 5)
    {
        std::cout << "You lose" << std::endl;
        return;
    }
    std::cout << "You won" << std::endl;
    return;
}

int main()
{
    unsigned short numbersAttempts;
    std::cout << "Wellcome to my game" << std::endl;
    std::cout << "Give number of attempts" << std::endl;
    std::cin >> numbersAttempts;
    for (unsigned short i = 0; i < numbersAttempts; i++)
    {
        std::cout << "                                " << std::endl;
        std::cout << "---------Gaming-----------------" << std::endl;
        std::cout << "Attempt number: " << i + 1 << std::endl;
        foo();
    }
    return 0;
}
