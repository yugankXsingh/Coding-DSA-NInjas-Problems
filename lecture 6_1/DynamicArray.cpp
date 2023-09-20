#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int capacity;
    int nextIndex;

public:
    DynamicArray() // Paracmeterized constructor
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    void add(int index, int element)
    {
        if (index < nextIndex)
        {
            data[index] = element;
        }
        else if (index == nextIndex)
        {
            data[nextIndex] = element;
            nextIndex++;
        }
        else
        {
            return;
        }
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int get(int index)
    {
        if (index < nextIndex)
        {
            return data[index];
        }
        else
        {
            return -1;
            cout << " : Invalid command request" << endl;
        }
    }

    // Copy constructor
    DynamicArray(DynamicArray const &d2)
    {
        // this->data = d2.data; // Shallow copy

        // Deep copy
        this->data = new int[d2.capacity];
        for (int i = 0; i < d2.nextIndex; i++)
        {
            this->data[i] = d2.data[i];
        }

        this->capacity = d2.capacity;
        this->nextIndex = d2.nextIndex;
    }

    void operator=(DynamicArray const &d2)
    { // this->data = d2.data; // Shallow copy

        // Deep copy
        this->data = new int[d2.capacity];
        for (int i = 0; i < d2.nextIndex; i++)
        {
            this->data[i] = d2.data[i];
        }

        this->capacity = d2.capacity;
        this->nextIndex = d2.nextIndex;
    }
};