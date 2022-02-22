#include <iostream>

int main()
{
    int number;
    std::cout << "Please enter your number: ";
    std::cin >> number;

    // if ((number >= 0 && number <= 10) == true)
    // {
    //     if (number == 4)
    //     {
    //         std::cout << "You won" << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "You lose" << std::endl;
    //     }
    // }
    // else
    // {
    //     std::cout << "Number not in rage 0-10" << std::endl;
    // }

    //Variante one esle oder else if
    if (!(number >= 0 && number <= 10))
    {
        std::cout << "Number not in rage 0-10" << std::endl;
        return 0;
    }
    if (number % 2 == 0) //rest division is equal  0
    {
        std::cout << "You won the Spoon" << std::endl;
        return 0;
    }
    if (number != 5)
    {
        std::cout << "You lose" << std::endl;
        return 0;
    }
    std::cout << "You won" << std::endl;
    return 0;
}
