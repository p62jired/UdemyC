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
int main()
{
    std::vector<int> my_vector1(10, 0);
    std::vector<int> my_vector2(10, 0);
    std::vector<int> my_vector3(10, 0);

    std::iota(my_vector1.begin(), my_vector1.end(), 0);
    print_vector(my_vector1);

    auto result1 = std::reduce(my_vector1.begin(), my_vector1.end());
    std::cout << result1 << std::endl;

    auto result2 = std::reduce(my_vector1.begin(), my_vector1.end(), 2);
    std::cout << result2 << std::endl;

    return 0;
}
