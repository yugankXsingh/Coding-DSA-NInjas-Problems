#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    // Write your code here

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m];
    }

    // dp[i][j]  will store the  maximum length of square ending at index i,j with all zeros

    // Base case
    // Fill the top row
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = (arr[0][j] == 0);
    }

    // Fill the first column
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = (arr[i][0] == 0);
    }

    int maxAns = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {

                int a = dp[i - 1][j - 1];
                int b = dp[i - 1][j];
                int c = dp[i][j - 1];

                dp[i][j] = min(a, min(b, c)) + 1;
                maxAns = max(dp[i][j], maxAns);
            }
        }
    }

    return maxAns;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}