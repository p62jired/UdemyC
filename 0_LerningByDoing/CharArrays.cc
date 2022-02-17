#include <iostream>

int main()
{
    char firstName[] = {'D', 'i', 'e', 'g', 'o', '\0'};
    std::cout << firstName << std::endl;
    char lastName[] = "Jimenez";
    for (unsigned short i = 0; i < sizeof(lastName) - 1; i++)
    {
        std::cout << "Last name [i]:  " << lastName[i] << std::endl;
    }

    return 0;
}
