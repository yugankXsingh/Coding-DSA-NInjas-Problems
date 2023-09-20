#include <iostream>
using namespace std;
#include <climits>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class stacksUsingArrays
{
    // private:
    //     int *data;
    //     int capacity;
    //     int nextIndex;

    // public:
    //     stacksUsingArrays()
    //     {
    //         data = new int[4];
    //         nextIndex = 0;
    //         capacity = 4;
    //     }

    //     void push(int element)
    //     {
    //         if (nextIndex == capacity)
    //         {
    //             int *newdata = new int[2 * capacity];
    //             for (int i = 0; i < capacity; i++)
    //             {
    //                 newdata[i] = data[i];
    //             }
    //             delete[] data;
    //             data = newdata;
    //             capacity = 2 * capacity;
    //         }
    //         data[nextIndex] = element;
    //         nextIndex++;
    //         return;
    //     }

    //     int top()
    //     {
    //         if (nextIndex == 0)
    //         {
    //             return -1;
    //         }
    //         return data[nextIndex - 1];
    //     }

    //     void pop()
    //     {
    //         if (nextIndex == 0)
    //         {
    //             cout << "Stack is Empty" << endl;
    //             return;
    //         }
    //         nextIndex--;
    //     }

    //     int size()
    //     {
    //         return nextIndex;
    //     }

    //     bool isEmpty()
    //     {
    //         return nextIndex == 0;
    //     }

    // Using Linked List
};

class stacksUsingLL
{
private:
    Node *head;

    int size;

public:
    stacksUsingLL()
    {
        this->head = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *newnode = new Node(data);

        newnode->next = head;
        head = newnode;
        size++;
    }

    bool isempty()
    {
        return head == NULL;
    }

    int top()
    {
        if (isempty)
        {
            return INT_MIN;
        }
        return head->data;
    }

    int pop()
    {
        if (isempty)
        {
            return INT_MIN;
        }

        int ans = head->data;
        Node *temp = head;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }

    int getsize()
    {
        return size;
    }
};

class queueUsingArray
{
    int *data;
    int nextindex;
    int frontindex;
    int size;
    int capacity;

public:
    queueUsingArray(int s)
    {
        data = new int[s];
        nextindex = 0;
        frontindex = -1;
        size = 0;
        capacity = s;
    }

    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        return size == 0;
    }

    void enqueue(int element)
    {

        if (size == capacity)
        {
            int *newdata = new int[2 * capacity];
            int j = 0;
            for (int i = frontindex; i < capacity; i++)
            {
                newdata[j] = data[i];
                j++;
            }
            for (int i = 0; i < frontindex; i++)
            {
                newdata[j] = data[i];
                j++;
            }

            delete[] data;
            data = newdata;
            capacity *= 2;
            frontindex = 0;
            nextindex = capacity;
            frontindex = 0;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;
        size++;
        if (isempty() || frontindex == -1)
        {
            frontindex = 0;
        }
    }

    int front()
    {
        if (frontindex == -1)
        {
            return INT_MIN;
        }
        return data[frontindex];
    }

    void dequeue()
    {
        if (frontindex == -1)
        {
            cout << "Empty queue" << endl;
            return;
        }
        frontindex = (frontindex + 1) % capacity;
        size--;

        if (size == 0)
        {
            frontindex = -1;
            nextindex = 0;
        }
    }
};