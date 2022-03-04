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
std::map<std::string, int> memo;

bool canSum(const int &targetSum, std::vector<int> &numbers)
{
    const std::string s_targetSum = std::to_string(targetSum);
    if (memo.count(s_targetSum) > 0)
    {
        return memo[s_targetSum];
    }
    if (targetSum == 0)
    {

        return true;
    }
    if (targetSum < 0)
    {

        return false;
    }

    for (std::size_t i = 0; i < numbers.size(); i++)
    {
        const int remainder = targetSum - numbers[i];
        if (canSum(remainder, numbers) == true)
        {
            memo[s_targetSum] = true;
            return true;
        }
    }
    memo[s_targetSum] = false;
    return false;
}


int main()
{
    int target = 250;

    std::vector<int> v = {2, 4};
    std::cout << std::boolalpha << canSum(target, v) << std::endl;

    // target = 250;
    // std::cout << std::boolalpha << canSum(target, v) << std::endl;

    return 0;
}
