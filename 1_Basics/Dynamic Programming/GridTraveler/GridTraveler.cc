#include <iostream>
#include <map>
#include <string>
std::map<std::string, double> memo;
double gridTraveler(const int &m, const int &n)
{

    const std::string key = std::to_string(m) + "," + std::to_string(n);
    if (memo.count(key) > 0)
    {
        return memo[key];
    }

    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m == 0 || n == 0)
    {
        return 0;
    }
    memo[key] = gridTraveler(m - 1, n) + gridTraveler(m, n - 1);

    // for (const auto &n : memo)
    // {
    //     std::cout << n.first << " = " << n.second << "; ";
    // }
    return memo[key];
}
int main()
{

    std::cout << gridTraveler(1, 1) << std::endl;
    std::cout << gridTraveler(2, 3) << std::endl;
    std::cout << gridTraveler(3, 2) << std::endl;
    std::cout << gridTraveler(3, 2) << std::endl;
    std::cout << gridTraveler(3, 3) << std::endl;
    std::cout << gridTraveler(18, 18) << std::endl;

    return 0;
}
