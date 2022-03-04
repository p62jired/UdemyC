#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
int increment(int i)
{
    return ++i;
}
int add(int i, int j)
{
    return i + j;
}
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
    std::transform(my_vector1.begin(), my_vector1.end(), my_vector2.begin(), increment);
    print_vector(my_vector2);

    std::transform(my_vector1.begin(), my_vector1.end(), my_vector2.begin(), my_vector3.begin(), add);
    print_vector(my_vector3);

    return 0;
}
