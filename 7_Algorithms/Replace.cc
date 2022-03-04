#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

void print_vector(std::vector<int> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "Ve[" << i << "] = " << vec[i] << std::endl;
    }
    std::cout << std::endl;
}


bool replace_even(const int i)
{
    return (i % 2 == 0);
}
int main()
{
    std::vector<int> my_vector1(10, 0);
    std::vector<int> my_vector2(10, 0);
    std::vector<int> my_vector3(10, 0);

    std::iota(my_vector1.begin(), my_vector1.end(), 1);
    print_vector(my_vector1);

    std::replace(my_vector1.begin(), my_vector1.end(), 2, 1337);
    print_vector(my_vector1);

    std::replace_if(my_vector1.begin(), my_vector1.end(), replace_even, -1);


    print_vector(my_vector1);

    return 0;
}
