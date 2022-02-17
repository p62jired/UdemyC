#include <iostream>

#include "exercise.h"

namespace computation
{

// Exercise 1
double mean_array_value(int *array, const unsigned int &length)
{
    float tmp_val = 0;
    double retVal = 0;
    for (unsigned int i = 0; i < length; i++)
    {
        tmp_val = tmp_val + static_cast<float>(array[i]);
    }

    tmp_val = tmp_val / static_cast<float>(length);
    retVal = static_cast<double>(tmp_val);

    return retVal;
}

double mean_array_value(double *array, const unsigned int &length)
{
    float tmp_val = 0;
    double retVal = 0;
    for (unsigned int i = 0; i < length; i++)
    {
        tmp_val = tmp_val + static_cast<float>(array[i]);
    }

    tmp_val = tmp_val / static_cast<float>(length);

    retVal = static_cast<double>(tmp_val);

    return retVal;
}
} // namespace computation
// namespace computation
