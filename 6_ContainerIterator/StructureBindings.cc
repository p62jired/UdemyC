#include <iostream>
#include <map>
#include <string>
#include <tuple>

std::tuple<int, std::string, double> get_data()
{
    return std::make_tuple(135, "data", 15864.0);
}
int main()
{
    const auto [id, name, score] = get_data();
    std::cout << id << std::endl;
    std::cout << name << std::endl;
    std::cout << score << std::endl;

    return 0;
}
