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
std::map<std::string, bool> memo;

std::optional::std::vector<std::size_t> howSum(const std::size_t &targetSum, std::vector<std::size_t> &numbers)
{
    std::vector<size_t> my_result;
    if (targetSum == 0)
    {
        return my_result;
    }
    if (targetSum < 0)
    {
        return std::nullopt;
    }
    std::vector<int> my_result;
    if
        for (std::size_t i = 0; i < numbers.size(); i++)
        {
            const int remainder = targetSum - numbers[i];
            const auto remeinder_result = howSum(remainder, numbers);
            if (remainder < 0)
            {
                return my_result;
            }
            if (remainder == 0)
            {
                my_result.push_back(numbers[i]);
                return my_result;
            }
        }


    int main()
    {
        int target = 300;

        std::vector<int> v = {7, 14};
        std::cout << std::boolalpha << canSum(target, v) << std::endl;

        // target = 250;
        // std::cout << std::boolalpha << canSum(target, v) << std::endl;

        return 0;
    }
