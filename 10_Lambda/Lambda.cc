#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void print_vector(std::vector<int> &vec)
{
    for (const auto &val : vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}

bool check_even(const int val)
{
    if (val % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    std::vector<int> my_vector(10, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    print_vector(my_vector);

    //transfor: element-wise operations
    std::vector<int> my_result(10, 0);

    // std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), check_even);
    // print_vector(my_result);

    std::transform(my_vector.begin(), my_vector.end(), my_result.begin(), [](const int val) -> int {
        if (val % 2 == 0)
            return 1;
        return 0;
    });
    print_vector(my_result);

    //copy if
    std::vector<int> my_result2;
    std::copy_if(my_vector.begin(), my_vector.end(), std::back_inserter(my_result2), [](const int val) -> int {
        if (val % 2 == 0)
            return 1;
        return 0;
    });
    print_vector(my_result2);

    return 0;
}
