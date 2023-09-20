#include <iostream>
using namespace std;
#include <algorithm>

int maximumProfit(int budget[], int n)
{
    // Write your code here
    sort(budget, budget + n);

    int *price = new int[n];
    for (int i = 0; i < n; i++)
    {
        price[i] = budget[i] * (n - i); // Profits corresponding to each price are stored.
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (price[i] > max)
        {
            max = price[i];
        }
    }
    return max;
}

int main()
{
    return 0;
}