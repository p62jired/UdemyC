#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(std::vector<int> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "Vec[" << i << "] = " << vec[i] << std::endl;
    }
    std::cout << std::endl;
}

void print_vector_info(std::vector<int> &vec)
{

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Empty?: " << std::boolalpha << vec.empty() << std::endl;
}
bool sort_ascending(const int a, const int b)
{
    return a < b;
}
bool sort_descending(const int a, const int b)
{
    return a > b;
}
int main()
{

    std::vector<int> my_vector(10, 5);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);

    std::sort(my_vector.begin(), my_vector.end(), sort_descending);
    print_vector(my_vector);

    std::sort(my_vector.begin(), my_vector.end(), sort_ascending);
    print_vector(my_vector);


    return 0;
}
