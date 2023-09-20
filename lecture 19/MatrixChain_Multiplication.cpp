#include <iostream>
using namespace std;
#include <bits/stdc++.h>

///////////////////////////////////////////////////////// Recursive Brute-force Approach ////////////////////////////////////////////////

int solve(int *arr, int s, int e)
{
    // base case
    if (s == e || s == e - 1)
    { // if s == e then don't have any matrix to compute
      // if s == e-1 then we have only one matrix to compute so ans will be 0
      // so no. of operations will be zero
        return 0;
    }

    int minAns = INT_MAX;
    for (int k = s + 1; k <= e - 1; k++)
    {
        // compute the left split
        int leftSplit = solve(arr, 0, k);

        // compute right split
        int rightSplit = solve(arr, k, e);

        // finally compute the operations perfromed after the multiplicatio of
        // left and right part
        // dimension of final left matrix = arr[s] * arr[k]
        // dimension of final right matrix = arr[k] * arr[e]
        int finalMultiplication = arr[s] * arr[k] * arr[e];

        // total operations
        int ans = leftSplit + rightSplit + finalMultiplication;

        if (ans < minAns)
        {
            minAns = ans;
        }
    }

    return minAns;

    // Time complexity is approximately --> O(n^n) -->exponential
}

int matrixChainMultiplication(int *arr, int n)
{
    // Write your code here

    // matrix M1 = a0*a1
    // matrix M2 = a1*a2
    // matrix M3 = a2*a3
    // .......
    // matrix Mn = an-1*an
    // size of arr is n+1
    // hence startIndex = 0 and endIndex = n

    return solve(arr, 0, n);
}

//////////////////////////////////////////////////////////////// Memoization //////////////////////////////////////////////////////////////

int solve_Mem(int *arr, int s, int e, int **dp)
{
    // base case
    if (s == e)
    {
        return 0;
    }

    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }

    int minAns = INT_MAX;

    for (int k = s; k <= e - 1; k++)
    {
        int leftSplit = solve_Mem(arr, s, k, dp);
        int rightSplit = solve_Mem(arr, k + 1, e, dp);
        int left_X_right = arr[s - 1] * arr[k] * arr[e];

        int ans = leftSplit + rightSplit + left_X_right;

        if (ans < minAns)
        {
            minAns = ans;
        }
    }

    dp[s][e] = minAns;

    return dp[s][e];
}

int matrixChainMultiplication_Mem(int *arr, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    return solve_Mem(arr, 1, n, dp);

    // Time complexity -->approx. O(n^3)
    // space complexity --> O(n^2) + O(n)
}

/////////////////////////////////////////////////////////// Bottom-Up approach- Tabulation ///////////////////////////////////////////

int matrixChainMultiplication_Tab(int *arr, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[n + 1];
    }

    // analyse base case
    // i.e, for every i==j dp[i][j] = 0
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // changing parameters --> s from 1 to n ans e from

    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int minAns = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int leftSplit = dp[i][k];
                int rightSplit = dp[k + 1][j];
                int left_X_right = arr[i - 1] * arr[k] * arr[j];

                int ans = leftSplit + rightSplit + left_X_right;

                if (ans < minAns)
                {
                    minAns = ans;
                }
            }

            dp[i][j] = minAns;
        }
    }

    return dp[1][n];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication_Tab(arr, n) << endl;
    cout << matrixChainMultiplication_Mem(arr, n) << endl;
    cout << matrixChainMultiplication(arr, n) << endl;

    delete[] arr;
}
