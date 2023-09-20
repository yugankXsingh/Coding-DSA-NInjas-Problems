#include <iostream>
using namespace std;
#include <climits>

class stackUsingArrays
{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackUsingArrays()
    {
        data = new int[4];
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
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            // cout << "Stack Full." << endl;
            // return;
            
            int *newdata = new int[2 * capacity];

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
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty." << endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    // Reading top element
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty." << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};