#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////// Recursive ////////////////////////////////////////////////////////

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    int ans1 = 0;
    int ans2 = 0;

    // if first weight is included
    if (maxWeight - weights[0] >= 0)
        ans1 = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];

    // first weight is not included
    ans2 = knapsack(weights + 1, values + 1, n - 1, maxWeight);

    return max(ans1, ans2);
}

/////////////////////////////////////////////////////////// Memoization ////////////////////////////////////////////////////////

int knapsack_Mem_helper(int *weights, int *values, int n, int maxWeight, int **dp)
{ // Base Case
    if (n == 0)
    {
        // dp[0][maxWeight] = 0;
        return 0;
    }

    int ans1 = 0;
    int ans2 = 0;

    // check if ans for index n and maxweight already present in dp array
    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }

    // if first weight is included
    if (maxWeight - weights[0] >= 0)
        ans1 = knapsack_Mem_helper(weights + 1, values + 1, n - 1, maxWeight - weights[0], dp) + values[0];

    // first weight is not included
    ans2 = knapsack_Mem_helper(weights + 1, values + 1, n - 1, maxWeight, dp);

    dp[n][maxWeight] = max(ans1, ans2);

    return dp[n][maxWeight];
}

int knapsack_Mem(int *weights, int *values, int n, int maxWeight)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = knapsack_Mem_helper(weights, values, n, maxWeight, dp);

    // print the dp array to verify your dry rum

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < maxWeight + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // return ans;
}

/////////////////////////////////////////////////////// Bottom Up approach //////////////////////////////////////////////////////////////

int knapsack_iterative(int *weights, int *values, int n, int maxWeight)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight + 1];
    }

    //  dp[i][j] = maximum value that can be obtained from selecting items
    //  from i number of items and maximum allowed weight equal to j

    // dp[0][j] = there will be 0 value from selecting 0 items
    // hence dp[0][j] = 0
    for (int j = 0; j <= maxWeight; j++)
    {
        dp[0][j] = 0;
    }

    // dp[i][0] = there will be 0 value from if the maximum allowed weight is 0
    // hence dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // fill the remaining dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            int include = 0;
            if (weights[i - 1] <= j)
            {
                include = values[i - 1] + dp[i - 1][j - weights[i - 1]];
            }

            int exclude = dp[i - 1][j];

            dp[i][j] = max(include, exclude);
        }
    }

    return dp[n][maxWeight];
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack_Mem(weights, values, n, maxWeight) << endl;
    cout << knapsack_iterative(weights, values, n, maxWeight) << endl;
    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}