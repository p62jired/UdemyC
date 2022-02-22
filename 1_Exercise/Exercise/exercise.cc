#include "exercise.h"
#include <iostream>

void mod_cross_sum(int I, int J)
{
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            int val = i + j;
            if (val % 2 == 0)
            {
                std::cout << "i: " << i << " ,"
                          << " j: " << j << " := Gerade" << std::endl;
            }
            else
            {
                std::cout << "i: " << i << " ,"
                          << " j: " << j << " := Ungerade" << std::endl;
            }
        }
    }
}
