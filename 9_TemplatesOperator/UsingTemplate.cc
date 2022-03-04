#include <iostream>
#include <map>
#include <vector>

template <typename T>
//with typedef does not work with template
// typedef UserData = std::map<int, std::vector<T>>;
using UserData = std::map<int, std::vector<T>>;

int main()
{
    UserData<double> my_double_data;
    UserData<float> my_double_float;

    return 0;
}
