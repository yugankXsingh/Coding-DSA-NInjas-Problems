#include <bits/stdc++.h>
#include <iostream>
using namespace std;

////////////////////////////////////////////////// Recursive /////////////////////////////////////////////////////////////////////////////////
int minCount_1(int n)
{
    // base case
    if (n == 0)
    {
        // cannot be created using perfect squares
        return 0;
    }

    int count = n; //  let initially each assume each number is created using 1 square only

    for (int i = 1; i * i <= n; i++)
    {
        count = min(count, minCount_1(n - i * i) + 1);
    }

    return count;
}

////////////////////////////////////////////////// Memoization ///////////////////////////////////////////////////////////////////////////
int minCount_helper(int n, int *arr)
{
    // base case
    if (n == 0)
    {
        // cannot be created using perfect squares
        return 0;
    }

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int count = n; //  let initially each assume each number is created using 1 square only

    for (int i = 1; i * i <= n; i++)
    {
        count = min(count, minCount_helper(n - i * i, arr) + 1);
    }

    arr[n] = count;

    return arr[n];
}

int minCount_2(int n)
{
    // Write your code here

    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    return minCount_helper(n, arr);
}

////////////////////////////////////////////////////////////////// Bottom-Up approach //////////////////////////////////////////////////////////

int minCount_3(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = INT_MAX;
    }

    // fill initial values
    arr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            int temp = j * j;
            if (temp >= 0)
            {
                arr[i] = min(arr[i], 1 + arr[i - temp]);
            }
        }
    }

    return arr[n];
}

int main()
{
    int N;
    cin >> N;
    cout << minCount_1(N) << endl;
    cout << minCount_2(N) << endl;
    cout << minCount_3(N) << endl;
}