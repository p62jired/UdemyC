#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class MyLinkedList
{
public:
    struct Node
    {
        int m_value;
        Node *m_next;
        Node(int val) : m_value(val), m_next(NULL)
        {
        }
    };

    Node *head;

    MyLinkedList() : head(NULL)
    {
    }

    int get(int index)
    {
        Node *ptr = head;
        int it = 0;
        if (it == index)
        {
            return ptr->m_value;
        }

        while (it < index)
        {
            if (ptr->m_next == nullptr)
            {
                return -1;
            }
            ptr = ptr->m_next;
            ++it;
        }
        return ptr->m_value;
    }

    void addAtHead(int val)
    {
        //1. Create new node
        Node *newNode = new Node(val);
        //2. Put it in front of current head
        newNode->m_next = head;
        //3. Move head of the list to point to the newNode
        head = newNode;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        Node *ptr = head;
        if (ptr == NULL)
        {
            addAtHead(val);
            return;
        }

        while (ptr->m_next != nullptr)
        {
            ptr = ptr->m_next;
        }
        ptr->m_next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        Node *newNode = new Node(val);
        Node *ptr = head;
        int i = 0;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        if (ptr->m_next == nullptr)
        {
            addAtTail(val);
            return;
        }

        while (ptr->m_next != nullptr)
        {
            if (i == index)
            {
                newNode->m_next = ptr->m_next;
                ptr->m_next = newNode;
                break;
            }
            ++i;
        }
    }

    void deleteAtIndex(int index)
    {
        Node *ptr = head;
        int i = 0;

        if (i == index)
        {
            Node *delGoalPtr = head;
            head = ptr->m_next;
            delete delGoalPtr;
            return;
        }
        int maxIndex = 0;
        Node *itrPtr = head;
        while (itrPtr->m_next != nullptr)
        {
            ++maxIndex;
            itrPtr = itrPtr->m_next;
        }
        if (index > maxIndex)
        {
            return;
        }
        if (index == maxIndex)
        {
            while (ptr->m_next != nullptr)
            {
                ptr = ptr->m_next;
            }

            delete ptr;
            return;
        }
        i = 0;
        while (i < index - 1)
        {
            ++i;
            ptr = ptr->m_next;
        }
        Node *delGoalPtr = ptr->m_next;
        ptr->m_next = delGoalPtr->m_next;
        delete delGoalPtr;
    }
};

struct ExpressionPrinter
{
    std::ostringstream oss;
    void print(MyLinkedList *list)
    {
        MyLinkedList::Node *ptr = list->head;
        while (ptr != nullptr)
        {
            oss << "Addr: ";
            oss << ptr;
            oss << " - Value: ";
            oss << ptr->m_value;
            oss << " - Next address: ";
            oss << ptr->m_next;
            oss << std::endl;
            ptr = ptr->m_next;
        }
    }
    std::string str() const
    {
        return oss.str();
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(2);
    obj->deleteAtIndex(1);
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);

    ExpressionPrinter ep;
    ep.print(obj);
    std::cout << ep.str() << std::endl;


    return 0;
}
