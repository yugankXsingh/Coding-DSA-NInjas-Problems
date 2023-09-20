#include <iostream>
using namespace std;
#include <climits>

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class stackUsingLL
{
    Node<T> *head;
    int size;

public:
    stackUsingLL()
    {
        head = NULL;
        size = 0;
    }

    void push(T element)
    {
        Node<T> *newnode = new Node<T>(element);

        if (head == NULL)
        {
            head = newnode;
            size++;
            return;
        }

        newnode->next = head;
        head = newnode;
        size++;
    }

    T top()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }

    T pop()
    {
        if (head == NULL)
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};