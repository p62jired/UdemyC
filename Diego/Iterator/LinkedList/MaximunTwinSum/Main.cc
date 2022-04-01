/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode
{
public:
    int m_value;
    ListNode *m_next;
};
#include <algorithm>

#include <iostream>
#include <unordered_set>
#include <vector>


class Solution
{
public:
    int pairSum(ListNode *head)
    {
        std::vector<int> v;
        std::vector<int> vSums;
        // int result = 0;
        while (head->m_next != nullptr)
        {
            v.push_back(head->m_value);
            head = head->m_next;
        }
        v.push_back(head->m_value);

        for (size_t i = 0; i != v.size() / 2; i++)
        {
            vSums.push_back(v[i] + v[v.size() - 1 - i]);
        }

        // for (const auto &value : vSums)
        // {
        //     if (result < value)
        //     {
        //         result = value;
        //     }
        //     std::cout << value << "\n";
        // }
        // return result;
        auto it = max_element(vSums.begin(), vSums.end());
        std::cout << *it << std::endl;
        return *it;
    }

    bool containsDuplicate(std::vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        // for (const auto &i : nums)
        //     std::cout << i << ' ' << std::endl;

        for (auto it = nums.begin(); it != nums.end() - 1; ++it)
        {
            for (auto it2 = it + 1; it2 != nums.end(); ++it2)
            {
                if (*it == *it2)
                {
                    return true;
                }
                if (*it < *it2)
                {
                    break;
                }
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_set<int> set;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (set.count(nums[i]))
        //         return true;
        //     set.insert(nums[i]);
        //     if (set.size() > k)
        //         set.erase(nums[i - k]);
        // }
        // return false;

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (set.count(*it))
                return true;
            set.insert(*it);
            if ((int)set.size() > k)
                set.erase(*(it - k));
        }
        return false;
    }

    bool containsNearbyDuplicate3(std::vector<int> &nums, int k, int t)
    {
        std::unordered_multiset<long> set;

        if (k < 1 || t < 0)
            return false;

        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            set.insert((long)*it);
            if ((int)set.size() > 1)
            {
                for (auto it2 = ++set.begin(); it2 != set.end(); ++it2)
                {
                    if (abs(*it2 - *it) <= t)
                    {
                        return true;
                    }
                }
            }
            if ((int)set.size() > k)
                set.erase(*(it - k));
        }
        return false;
    }
};

void printList(ListNode *head)
{

    while (head->m_next != nullptr)
    {
        std::cout << head->m_value << std::endl;
        head = head->m_next;
    }
    std::cout << head->m_value << std::endl;
}

int main()
{
    ListNode *head = new ListNode();
    ListNode *second = new ListNode();
    ListNode *thrid = new ListNode();
    ListNode *fourth = new ListNode();
    // ListNode *fifth = new ListNode();
    head->m_value = 1;
    second->m_value = 2;
    thrid->m_value = 3;
    fourth->m_value = 6;
    // fifth->m_value = 5;

    head->m_next = second;
    second->m_next = thrid;
    thrid->m_next = fourth;
    // fourth->m_next = fifth;
    // fifth->m_next = nullptr;
    fourth->m_next = nullptr;
    // fifth->m_next = nullptr;

    Solution resultSolution;
    std::cout << resultSolution.pairSum(head) << std::endl;


    std::vector<int> vDuplicate{-40, -1, 1, 3, 5, 6, 87, 7, 5};
    // std::cout << std::boolalpha << resultSolution.containsDuplicate(vDuplicate) << std::endl;

    vDuplicate = {1, 2, 3, 1, 2, 3};
    // for (const auto &i : vDuplicate)
    //     std::cout << i << ' ' << std::endl;
    // std::cout << std::boolalpha << resultSolution.containsNearbyDuplicate(vDuplicate, 2) << std::endl;
    // vDuplicate = {1, 5, 9, 1, 5, 9};
    // vDuplicate = {1, 2, 3, 1};
    vDuplicate = {-2147483648, 2147483647};
    std::cout << std::boolalpha << resultSolution.containsNearbyDuplicate3(vDuplicate, 1, 1) << std::endl;
    return 0;
}
