#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//////////////////////////////////////////////////////// Recursive-brute Force ////////////////////////////////////////////////////////

int minCostPath_Helper(int **input, int rows, int cols, int x, int y)
{

    // BASE CASE
    if (x == rows - 1 && y == cols - 1)
    {
        return input[x][y];
    }

    int right = INT_MAX, down = INT_MAX, diagonal = INT_MAX;

    if (y + 1 < cols)
        // move right
        right = minCostPath_Helper(input, rows, cols, x, y + 1);

    if (x + 1 < rows)
        // move down
        down = minCostPath_Helper(input, rows, cols, x + 1, y);

    if (x + 1 < rows && y + 1 < cols)
        // move diagonally
        diagonal = minCostPath_Helper(input, rows, cols, x + 1, y + 1);

    int minCost = min(right, min(down, diagonal));

    int cost = minCost + input[x][y];
    return cost;

    // on each step we are making 3 calls
    // Time complexity --> O(3^m or 3^n provided which is greater among m , n)
}

int minCostPath(int **input, int m, int n)
{
    // Write your code here

    return minCostPath_Helper(input, m, n, 0, 0);
}

//////////////////////////////////////////////////////// Memoization ////////////////////////////////////////////////////////

int minCostPath_Mem_Helper(int **input, int rows, int cols, int x, int y, int **&dp)
{
    // BASE CASE
    if (x == rows - 1 && y == cols - 1)
    {
        return input[x][y];
    }

    // check if min cost from (x,y) to (rows-1 , cols-1) is present in the dp array
    // dp[x][y] --> represents the min cost from (x,y) to (rows-1 , cols-1)

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    // else calculate the min cost

    int right = INT_MAX, down = INT_MAX, diagonal = INT_MAX;

    if (y + 1 < cols)
        // move right
        right = minCostPath_Mem_Helper(input, rows, cols, x, y + 1, dp);

    if (x + 1 < rows)
        // move down
        down = minCostPath_Mem_Helper(input, rows, cols, x + 1, y, dp);

    if (x + 1 < rows && y + 1 < cols)
        // move diagonally
        diagonal = minCostPath_Mem_Helper(input, rows, cols, x + 1, y + 1, dp);

    int minCost = min(right, min(down, diagonal));

    int cost = minCost + input[x][y];

    // save the answer for future use
    dp[x][y] = cost;
    return dp[x][y];

    // Total number of unique calls = m*n
    // Time complexity --> O(m*n)
    // Space complexity --> O(m*n)
}

int minCostPath_Mem(int **input, int m, int n)
{
    // create a 2D array
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }

    // initialize each cell of dp with -1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    return minCostPath_Mem_Helper(input, m, n, 0, 0, dp);
}

///////////////////////////////////////////////////////////// bottom-Up approach //////////////////////////////////////////////////

int minCostPath_iterative(int **input, int m, int n)
{
    // create a 2D array
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }

    // fill the last destination cell
    dp[m - 1][n - 1] = input[m - 1][n - 1];

    // fill the bottom last row
    for (int j = n - 2; j >= 0; j--)
    {
        dp[m - 1][j] = dp[m - 1][j + 1] + input[m - 1][j];
    }

    // fill the last column
    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = dp[i + 1][n - 1] + input[i][n - 1];
    }

    // fill the remaining matrix
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = min(dp[i][j + 1], min(dp[i + 1][j + 1], dp[i + 1][j])) + input[i][j];
        }
    }

    return dp[0][0];

    // Time complexity --> O(m*n)
    // Space complexity --> O(m*n)
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
    cout << minCostPath_Mem(arr, n, m) << endl;
    cout << minCostPath_iterative(arr, n, m) << endl;
}