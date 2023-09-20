#include <iostream>
using namespace std;
#include <queue>

void KsortedArray(int *input, int n, int k)
{
    priority_queue<int> pq;
    // insert 1st k elements into the queue
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    int j = 0;
    for (int i = k; i < n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    // K elements are still in the priority queue
    // insert them into the array
    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}


int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int size = 5;
    int k = 3;
    KsortedArray(input, size, k);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}