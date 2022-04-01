
#include <iostream>
#include <vector>

class Node
{
public:
    int m_value;
    Node *m_next;
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
void insertAtTheFront(Node **head, int newVal)
{
    //1. Prepare a newNode
    Node *newNode = new Node();
    newNode->m_value = newVal;

    //2, Put it in front of current head

    newNode->m_next = *head;
    //3. Move head of the list to point to the newNode
    *head = newNode;
}
void insertAtTheEnd(Node *node, int newVal)
{
    //1. Prepare a newNode
    Node *newNode = new Node();
    newNode->m_value = newVal;
    //2. Find the last Node
    while (node->m_next != nullptr)
    {
        node = node->m_next;
    }
    //3. Insert newNode after last node
    node->m_next = newNode;
}
void insertAfter(Node *node, int newVal)
{
    //1. Prepare a newNode
    Node *newNode = new Node();
    newNode->m_value = newVal;
    //2. Insert newNode before the next node
    newNode->m_next = node->m_next;
    //3. Insert newNode after
    node->m_next = newNode;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *thrid = new Node();
    head->m_value = 1;
    second->m_value = 2;
    thrid->m_value = 3;
    head->m_next = second;
    second->m_next = thrid;
    thrid->m_next = nullptr;

    insertAtTheFront(&head, -1);
    insertAtTheFront(&head, -2);
    insertAtTheEnd(head, 4);
    insertAtTheEnd(head, 5);
    insertAfter(second, 20);

    printList(head);
    return 0;
}
