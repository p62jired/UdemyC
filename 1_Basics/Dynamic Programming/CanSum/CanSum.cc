#include <iostream>
#include <map>
#include <string>
#include <vector>
//Writte a function "canSum(targetSum, numbers)" that takes in a targetSum and
//and array of numbers as arguments

//The function should return a boolean indicating whether or not it is possible
//to generate the targetSum using numbers from the array

//You may use an element of the array as many times as needed.

//You may assume that all input numbers are nonegative.

bool canSum(const std::size_t &targetSum, std::vector<std::size_t> &numbers)
{
    static std::size_t i_numbers = 0;
    if (numbers[i_numbers] == targetSum)
    {
        return true;
    }
    for (std::size_t i = i_numbers; i < numbers.size() - 1; i++)
    {
        if (numbers[i] + numbers[i + 1] == targetSum)
        {
            return true;
        }
    }
    ++i_numbers;

    if (i_numbers > numbers.size() - 1)
    {
        return false;
    }

    return canSum(targetSum, numbers);
}


int main()
{
    std::map<std::string, double> memo;
    std::vector<std::size_t> v = {5, 4, 4, 8};
    std::size_t target = 7;
    std::cout << std::boolalpha << canSum(target, v) << std::endl;


    return 0;
}
