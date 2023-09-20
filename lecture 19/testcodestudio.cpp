#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int m, int n, int i, int j)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        // we reached destination
        return 1; // path found;
    }

    if (i >= m || j >= n)
    {
        return 0;
    }

    // move right
    int right = (m, n, i, j + 1);

    // move down
    int down = (m, n, i + 1, j);

    return right + down;
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    return solve(m, n, 0, 0);
}

int main()
{
    int m, n;
    cin >> m, n;
    cout << uniquePaths(m, n);
}