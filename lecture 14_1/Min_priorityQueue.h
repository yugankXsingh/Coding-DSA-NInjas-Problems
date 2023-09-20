#include <iostream>
using namespace std;
#include <vector>

class Min_priorityQueue
{
    vector<int> pq;

public:
    Min_priorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int data)
    {
        pq.push_back(data);

        int childindex = pq.size() - 1;

        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
            {
                // child is smaller than parent
                // swap the parent and child
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                // child reached its correct position
                break;
            }

            // update the value of childindex after swaping
            childindex = parentindex;
        }
    }

    int removeMin()
    {
        if (pq.size() == 0)
        {
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;

        while (parentindex < pq.size())
        {

            int leftChildindex = 2 * parentindex + 1;
            int rightChildindex = 2 * parentindex + 2;
            int minindex;

            if (leftChildindex < pq.size() && rightChildindex < pq.size())
            {
                // both children are present

                if (pq[rightChildindex] > pq[leftChildindex])
                {
                    minindex = leftChildindex;
                }
                else
                {
                    minindex = rightChildindex;
                }
            }
            else if (leftChildindex < pq.size())
            {
                // only leftchild is present
                minindex = leftChildindex;
            }
            else
            {
                // no child is present
                break;
            }

            if (pq[parentindex] > pq[minindex])
            {
                // parent is greater than its smaller child
                // swap the parent with smaller child
                int temp = pq[parentindex];
                pq[parentindex] = pq[minindex];
                pq[minindex] = temp;
            }
            else
            {
                // parent is smaller than both children
                break;
            }

            // update the index of parent
            parentindex = minindex;
        }

        return ans;
    }
};