#include <iostream>
#include <type_traits>
template <typename T>
struct is_numeric : public std::disjunction<std::is_integral<T>, std::is_floating_point<T>>
{
    /* data */
};
template <typename T>
T max(T value_one, T value_two)
{
    static_assert(is_numeric<T>::value, "failed...");

    if (value_one < value_two)
    {
        return value_two;
    }
    else
    {
        return value_one;
    }
}

int main()
{
    int a = 2;
    int b = 3;

    std::cout << max(a, b) << std::endl;

    float c = 4.5f;
    float d = -1.0f;

    std::cout << max(c, d) << std::endl;


    return 0;
}
