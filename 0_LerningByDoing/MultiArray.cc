#include <iostream>

int main()
{
    int myMatrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for (unsigned short i = 0; i < 3; i++)
    {
        for (unsigned short j = 0; j < 2; j++)
        {
            std::cout << "i = " << i << " , j = " << j << " , value = " << myMatrix[i][j] << std::endl;
        }
    }
    return 0;
}
