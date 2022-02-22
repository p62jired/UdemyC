#include <iostream>
int getInput()
{
    int number;
    std::cout << "Please enter your number: ";
    std::cin >> number;
    return number;
}

void whatsMyNumber(int number)
{
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
    int myNumber = getInput();
    whatsMyNumber(myNumber);
}
