#include <iostream>
using namespace std;

////////////////////////////////////////////////////////// Recursive-Brute Force //////////////////////////////////////////////////

int solve_recursive(int *input, int n, int curr, int prev)
{
    // base case
    if (curr == n)
    {
        return 0;
    }

    int notTake = solve_recursive(input, n, curr + 1, prev);

    int take = 0;
    if (prev == -1 || input[curr] > input[prev])
    {
        take = 1 + solve_recursive(input, n, curr + 1, curr); // curr will move forward and prev will become curr
    }

    return max(take, notTake);

    // Time complexity --> O(2^n)
}

int LIS_Rec(int *input, int n)
{
    return solve_recursive(input, n, 0, -1);
}

//////////////////////////////////////////////////////////////////// Memoization //////////////////////////////////////////////////////

int solve_Mem(int *input, int n, int curr, int prev, int **dp)
{
    // base case
    if (curr == n)
    {
        return 0;
    }

    // check if LIS for curr index whose prev is prev is already present in the dp
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }

    int notTake = 0 + solve_Mem(input, n, curr + 1, prev, dp);

    int take = 0;
    if (prev == -1 || input[curr] > input[prev])
    {
        take = 1 + solve_Mem(input, n, curr + 1, curr, dp); // curr will move forward and prev will become curr
    }

    dp[curr][prev + 1] = max(take, notTake);

    return dp[curr][prev + 1];

    // Time complexity --> O(n^2)
}

int LIS_Mem(int *input, int n)
{
    // in the recursive solution we passed two variables i.e, curr and prev
    // curr varies form 0 to n-1
    // prev varies from -1 to n-1
    // as we cannot have an -1 index so a coordinate shift is required
    // -1th index = 0 , 0th index = 1st , 1st index = 2nd , ........ , n-1th index = nth index
    // hence we need a dp[n][n+1].

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] == -1;
        }
    }

    return solve_Mem(input, n, 0, -1, dp);
}
////////////////////////////////////////////////////////// Bottom-Up Approach //////////////////////////////////////////////////

int LIS(int *input, int n)
{
    // we need an output inputay
    int *output = new int[n];
    // this output inputay stores the length of LIS ending at index i

    output[0] = 1; // length of LIS ending at 0th index

    for (int i = 1; i < n; i++)
    {
        output[i] = 1; // this is the min. possible length for LIS ending at index i

        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] >= input[i])
            {
                continue;
            }

            int possibleAns = output[j] + 1;
            if (possibleAns > output[i])
            {
                output[i] = possibleAns;
            }
        }
    }

    // find the maximum value from the output array that will be the LIS

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (output[i] > best)
        {
            best = output[i];
        }
    }

    return best;

    // Time complexity --> O(n^2).
}

////////////////////////////////////// Space Optimization --> DP with Binary Search ///////////////////////////////////////////////////

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int ans = LIS(input, n); 
    int ans3 = LIS_Mem(input, n);
    int ans2 = LIS_Rec(input, n); 
    cout << ans << endl;
    cout << ans3 << endl;
    cout << ans2 << endl;

    delete[] input;

    return 0;
}