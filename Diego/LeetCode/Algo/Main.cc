#include <algorithm>
#include <iostream>
#include <vector>

// Given an array of integers nums which is sorted in ascending order,
// and an integer target, write a function to search target in nums.
// If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Approach 1: Binary Search

// Intuition

// Binary search is a textbook algorithm based on the idea to compare the target
// value to the middle element of the array.

// If the target value is equal to the middle element - we're done.

// If the target value is smaller - continue to search on the left.

// If the target value is larger - continue to search on the right.
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int pivot, left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target)
                return pivot;
            if (target < nums[pivot])
                right = pivot - 1;
            else
                left = pivot + 1;
        }
        return -1;
    }
};


class MyHashSet
{
public:
    std::vector<int> v;

    MyHashSet()
    {
    }

    void add(int key)
    {
        if (!contains(key))
        {
            v.push_back(key);
        }
    }

    void remove(int key)
    {
        if (contains(key))
        {
            v.erase(std::find(v.begin(), v.end(), key));
        }
    }

    bool contains(int key)
    {
        return std::find(v.begin(), v.end(), key) != v.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

class MyHashMap
{
public:
    class Data
    {
    public:
        int m_key;
        int m_value;
    };
    std::vector<Data> myVector;
    MyHashMap()
    {
    }

    void put(int key, int value)
    {

        if (get(key) == -1)
        {
            Data tmpData;
            tmpData.m_key = key;
            tmpData.m_value = value;
            myVector.push_back(tmpData);
        }
        else
        {
            for (auto it = myVector.begin(); it != myVector.end(); ++it)
            {
                if (it->m_key == key)
                {
                    it->m_value = value;
                }
            }
        }
    }


    int get(int key)
    {
        for (const auto v : myVector)
        {
            if (v.m_key == key)
            {
                return v.m_value;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        for (auto it = myVector.begin(); it != myVector.end(); ++it)
        {
            if (it->m_key == key)
            {
                myVector.erase(it);
                return;
            }
        }
    }
};

class MyLinkedList
{
public:
    class Node
    {
    public:
        int m_value = 0;
        Node *m_next;
        Node(int value, Node *next)
        {
            m_value = value, m_next = next;
        }
    };
    void printList(Node *node)
    {

        while (node->m_next != nullptr)
        {
            std::cout << node->m_value << std::endl;
            node = node->m_next;
        }
        std::cout << node->m_value << std::endl;
        // for (auto const nd : rVector)
        // {
        //     std::cout << nd.m_value << std::endl;
        // }
    }

    MyLinkedList()
    {
    }

    int get(int index)
    {
    }

    void addAtHead(int val)
    {
        Node *head = new Node(val, nullptr);
        // head->m_value = val;
    }

    void addAtTail(int val)
    {
    }

    void addAtIndex(int index, int val)
    {
    }

    void deleteAtIndex(int index)
    {
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
    Solution solution;
    MyHashSet *myHashSet = new MyHashSet();
    myHashSet->add(1);
    // std::cout << solution.search(myVec, 9) << std::endl;

    std::cout << myHashSet->contains(1) << std::endl;

    MyHashMap *myHashMap = new MyHashMap();
    myHashMap->put(1, 45);
    std::cout << myHashMap->get(1) << std::endl;
    myHashMap->remove(1);
    myHashMap->put(2, 1);
    myHashMap->put(2, 14);
    std::cout << myHashMap->get(2) << std::endl;


    return 0;
}
