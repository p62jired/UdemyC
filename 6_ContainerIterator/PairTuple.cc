
#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using tuple_user = std::tuple<int, std::string, bool>;
using pair_user = std::pair<int, std::string>;

void print_tuple(const tuple_user &tpl)
{
    std::cout << std::get<0>(tpl) << std::endl;
    std::cout << std::get<1>(tpl) << std::endl;
    std::cout << std::get<2>(tpl) << std::endl;
    std::cout << std::endl;
}

void print_pair(const pair_user &p)
{
    std::cout << p.first << std::endl;
    std::cout << p.second << std::endl;
}
int main()
{
    tuple_user my_tpl1(23, "Jan", true);
    tuple_user my_tpl2(25, "Diego", false);
    print_tuple(my_tpl1);
    pair_user my_pair(18, "Pepe");
    print_pair(my_pair);


    return 0;
}
