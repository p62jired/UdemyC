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

int adder(int i, int j)
{
    return i + j;
}
int multiplier(int i, int j)
{
    return i * j;
}
int main()
{
    std::vector<int> my_vector1(10, 0);
    std::vector<int> my_vector2(10, 0);
    std::vector<int> my_vector3(10, 0);

    std::iota(my_vector1.begin(), my_vector1.end(), 1);
    print_vector(my_vector1);

    auto result1 = std::accumulate(my_vector1.begin(), my_vector1.end(), 0);
    std::cout << result1 << std::endl;

    auto result2 = std::accumulate(my_vector1.begin(), my_vector1.end(), 0, adder);
    std::cout << result2 << std::endl;

    auto result3 = std::accumulate(my_vector1.begin(), my_vector1.end(), 1, multiplier);
    std::cout << result3 << std::endl;


    std::vector<int> data(3, 0);
    print_vector(data);
    std::iota(data.begin(), data.end(), 10);
    print_vector(data);
    std::cout << std::accumulate(data.begin(), data.end(), 0) << std::endl;

    return 0;
}
