#include <iostream>
using namespace std;

template <typename T>

class QueueUsingArray
{
    T *data;
    int size;
    int capacity;
    int frontIndex;
    int nextIndex;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        size = 0;
        capacity = s;
        frontIndex = -1;
        nextIndex = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            // cout << "Queue Full !" << endl;
            // return;
            T *newData = new T[2 * capacity];

            int j = 0;
            for (int i = frontIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < frontIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }

            // updating frontIndex and nextIndex
            frontIndex = 0;
            nextIndex = capacity;
            capacity *= 2; // upadting new capacity
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity; // we have to move nextIndex cyclically
        if (frontIndex == -1)
        {
            frontIndex = 0;
        }
        size++;
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty !" << endl;
            return 0;
        }
        T ans = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;

        if (size == 0) // not neccessary
        {
            nextIndex = 0;
            frontIndex = -1;
        }

        return ans;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty !" << endl;
            return 0;
        }
        return data[frontIndex];
    }
};