#include <iostream>

int main()
{
    int sum = 10;

    do
    {
        std::cout << "\nCurrente sum: " << sum << " Enter next value: ";
        int input;
        std::cin >> input;
        sum += input;

    } while (sum < 10);

    return 0;
}
