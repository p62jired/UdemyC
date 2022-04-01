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

class Node
{
public:
    int m_value;
    Node *m_next;
};
#include <iostream>
#include <vector>
class Solution
{
public:
    Node *middleNode(Node *node)
    {
        Node *tmpNode = new Node();
        tmpNode = node;
        int listLeng = 0;
        while (tmpNode->m_next != nullptr)
        {
            tmpNode = tmpNode->m_next;
            listLeng++;
        }
        listLeng++;
        std::cout << "Length: " << listLeng << std::endl;

        if (!listLeng % 2)
        {
            listLeng = (listLeng / 2) + 1;
        }
        listLeng = listLeng / 2;

        for (size_t i = 0; i != listLeng; i++)
        {
            node = node->m_next;
        }
        return node;
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

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *thrid = new Node();
    Node *fourth = new Node();
    // Node *fifth = new Node();
    head->m_value = 1;
    second->m_value = 2;
    thrid->m_value = 3;
    fourth->m_value = 4;
    // fifth->m_value = 5;

    head->m_next = second;
    second->m_next = thrid;
    thrid->m_next = fourth;
    // fourth->m_next = fifth;
    // fifth->m_next = nullptr;
    fourth->m_next = nullptr;
    // fifth->m_next = nullptr;

    auto resultSolution = new Solution();
    auto resultNode = resultSolution->middleNode(head);
    printList(resultNode);
    return 0;
}
