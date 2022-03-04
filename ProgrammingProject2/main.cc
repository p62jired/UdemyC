#include <cstddef>
#include <iostream>

#include "AlgoArray.h"
#include "DynArray.h"

// int main()
int main()
{
    double fill_value = 1.0;
    std::size_t length = 0;

    DynamicArray<double> my_array(fill_value, length);
    DynamicArray<double> my_array2;
    my_array.push_back(0);
    my_array.push_back(1);
    my_array.push_back(2);
    my_array.push_back(3);
    my_array.push_back(4);

    my_array2.push_back(0);
    my_array2.push_back(1);
    my_array2.push_back(2);


    std::cout << "Array my_array" << std::endl;
    for (std::size_t i = 0; i < my_array.get_length(); i++)
    {
        std::cout << my_array[i] << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Array my_array2" << std::endl;
    for (std::size_t i = 0; i < my_array2.get_length(); i++)
    {
        std::cout << my_array2[i] << std::endl;
    }
    std::cout << std::endl;

    my_array.pop_back();
    my_array.pop_back();

    std::cout << "Array my_array" << std::endl;
    for (std::size_t i = 0; i < my_array.get_length(); i++)
    {
        std::cout << my_array[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Mean = " << mean(my_array) << std::endl;
    std::cout << "Median = " << median(my_array) << std::endl;
    std::cout << "Variance = " << variance(my_array) << std::endl;
    std::cout << "Stddev = " << stddev(my_array) << std::endl;

    return 0;
}
