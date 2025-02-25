#include <iostream>

#include "exercise.h"

// Exercise 2
std::string get_oldest_friend(const Friends &friends)
{
    std::string oldest_friend;
    int oldest_age = 0;
    for (const auto &val : friends)
    {
        auto p = val.second;
        if (p.first > oldest_age)
        {
            oldest_age = p.first;
            oldest_friend = val.first;
        }
    }
    return oldest_friend;
}

std::string get_heaviest_friend(const Friends &friends)
{
    std::string heaviest_friend = "";
    int heaviest_age = 0;
    for (const auto &val : friends)
    {
        auto p = val.second;

        if (p.second > heaviest_age)
        {
            heaviest_age = p.second;
            heaviest_friend = val.first;
        }
    }
    return heaviest_friend;
}
