#include <iostream>
using namespace std;
#include <vector>

class MaxpriorityQueue
{
    vector<int> pq;

public:
    MaxpriorityQueue()
    {
    }

    void insert(int data)
    {
        pq.push_back(data);
        int childindex = pq.size() - 1;

        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] > pq[parentindex])
            {
                // if parent is samaller than child
                // swap parent and child

                int temp = pq[parentindex];
                pq[parentindex] = pq[childindex];
                pq[childindex] = temp;
            }
            else
            {
                // child is correctly placed
                break;
            }

            // update the childindex
            childindex = parentindex;
        }
    }

    int removeMax()
    {
        if (pq.size() == 0)
        {
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int leftChildIndex = 2 * parentindex + 1;
        int rightChildIndex = 2 * parentindex + 2;

        while (parentindex < pq.size())
        {
            int maxindex; // idex of greater child
            if (leftChildIndex < pq.size() && rightChildIndex < pq.size())
            {
                // both child are present
                if (pq[leftChildIndex] > pq[rightChildIndex])
                {
                    maxindex = leftChildIndex;
                }
                else
                {
                    maxindex = rightChildIndex;
                }
            }
            else if (leftChildIndex < pq.size())
            {
                // only leftchild is present
                maxindex = leftChildIndex;
            }
            else
            {
                // no child is present
                break;
            }

            if (pq[parentindex] < pq[maxindex])
            {
                // if parent is smaller than its bigger child
                // swap parent and children
                int temp = pq[parentindex];
                pq[parentindex] = pq[maxindex];
                pq[maxindex] = temp;
            }
            else
            {
                // child is coorectly placed
                break;
            }

            // update the index of parent
            parentindex = maxindex;
        }
        return ans;
    }
};