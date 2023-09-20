#include <iostream>
using namespace std;

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

class QueueUsingLL
{
    T data;
    int size;
    Node<T> *head;
    Node<T> *tail;

public:
    QueueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        size++;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }

        Node<T> *temp = head;
        T ans = head->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};