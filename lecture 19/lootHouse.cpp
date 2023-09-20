#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////// Recursive ////////////////////////////////////////////////

// int maxMoneyLooted_helper(int *arr, int index)
// {
//     // going from right to left in arr

//     //  base case
//     if (index < 0)
//     {
//         return 0;
//     }
//     if (index == 0)
//     {
//         // only 1 element is present in arr
//         return arr[index];
//     }

//     int include = maxMoneyLooted_helper(arr, index - 2) + arr[index];
//     int exclude = maxMoneyLooted_helper(arr, index - 1) + 0;
//     return max(include, exclude);
// }

int maxMoneyLooted(int *arr, int n)
{
    // Write your code here
    //  Base case
    if (n <= 0)
    {
        return 0;
    }

    int include = 0;
    include = maxMoneyLooted(arr + 2, n - 2) + arr[0];

    int exclude = 0;
    exclude = maxMoneyLooted(arr + 1, n - 1);

    return max(include, exclude);
}

//////////////////////////////////////////////////////////// Memoization ///////////////////////////////////////////////////////////

int maxMoneyLooted_Mem_Helper(int *arr, int n, int *dp)
{
    // base case
    if (n <= 0)
    {
        return 0;
    }

    // check if ans for n number of houses is already present in the dp array
    // dp[i] stores the maximum amount of money that can be looted from i number of houses starting from house index 0 to i-1

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int include = 0;
    include = maxMoneyLooted_Mem_Helper(arr + 2, n - 2, dp) + arr[0];

    int exclude = 0;
    exclude = maxMoneyLooted_Mem_Helper(arr + 1, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

int maxMoneyLooted_Mem(int *arr, int n)
{
    int *dp = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    return maxMoneyLooted_Mem_Helper(arr, n, dp);
}

//////////////////////////////////////////////////////////////////// Bottom-Up approach ////////////////////////////////////////
int maxMoneyLooted_iterative(int *arr, int n)
{
    int *dp = new int[n + 1];

    dp[0] = 0; //  dp[0] means there are 0 houses to loot so max. money will be 0

    for (int i = 1; i <= n; i++)
    {
        // when (i-1)th house in arr is included
        int inlude = dp[i + 2] + arr[i - 1];

        // when (i-1)th house in arr is not included
        int exclude = dp[i + 1] + 0;

        dp[i] = max(inlude, exclude);
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxMoneyLooted_Mem(arr, n);
    cout << maxMoneyLooted(arr, n) << endl;
    return 0;
}