#include <iostream>

#include "exercise.h"

// Exercise 1
double array_sum(const double *p_array, const unsigned int &length)
{
    double result = 0;
    for (unsigned int i = 0; i < length; i++)
    {
        result = result + p_array[i];
    }
    return result;
}

// Exercise 2
int *array_constructor(const int &value, const unsigned int &length)
{
    //new create a array of int in heap memory
    int *p = new int[length];
    for (unsigned int i = 0; i < length; i++)
    {
        p[i] = value;
    }
    //return the address value of the first int element in array (in heap)
    return p;
}
