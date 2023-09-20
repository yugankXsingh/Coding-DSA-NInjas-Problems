#include <iostream>
using namespace std;
#include <climits>

template <typename T>

class stackUsingArrays
{
    T *data;
    int nextIndex;
    int capacity;

public:
    stackUsingArrays()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    // Returning the no. of elements in the array
    int size()
    {
        return nextIndex;
    }

    // Checking weather stack is empty or not
    bool isEmpty()
    {
        // if (nextIndex == 0)
        // {
        //     return true;
        // }
        // else
        // {
        //     false;
        // }
        // OR

        return nextIndex == 0;
    }

    // Insert Element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack Full." << endl;
            // return;

            T *newdata = new T[2 * capacity];

            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }

            capacity *= 2;
            delete[] data;
            data = newdata;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // Delete element
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty." << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    // Reading top element
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty." << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};