#include <iostream>
bool isConditionToWin()
{
    int number;
    std::cout << "Please enter your number: ";
    std::cin >> number;
    if (!(number >= 0 && number <= 10))
    {
        std::cout << "Number not in rage 0-10" << std::endl;
        return false;
    }
    if (number % 2 == 0) //rest division is equal  0
    {
        std::cout << "You won the Spoon" << std::endl;
        return false;
    }
    if (number != 5)
    {
        std::cout << "You lose" << std::endl;
        return false;
    }
    std::cout << "You won" << std::endl;
    return true;
}

int main()
{
    std::cout << "Wellcome to my game" << std::endl;

    while (isConditionToWin() == false)
    {
        isConditionToWin();
    }

    return 0;
}
