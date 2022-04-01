#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    using ScoreMap = std::unordered_map<std::string, int>;
    ScoreMap map;
    map["Cherno"] = 5;
    map["Diego"] = 34;
    map["Pedro"] = 55;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    {
        auto &key = it->first;
        auto &value = it->second;
        std::cout << key << std::endl;
        std::cout << value << std::endl;
    }


    for (auto [key, value] : map)
    {

        std::cout << key << std::endl;
        std::cout << value << std::endl;
    }

    return 0;
}
