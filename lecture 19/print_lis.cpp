#include <iostream>
using namespace std;
#include <vector>

int LIS_UsingBinarySearch(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    int len = temp.size();

    return len;
}

int solve(int ind, int n, int prev_ind, int *arr, vector<vector<int>> &dp)
{
    // base case
    if (ind == n)
        return 0;

    if (dp[ind][prev_ind + 1] != -1)
    {
        return dp[ind][prev_ind + 1];
    }

    int take = 0;
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
    {
        take = 1 + solve(ind + 1, n, ind, arr, dp);
    }

    int notTake = solve(ind + 1, n, prev_ind, arr, dp);

    return dp[ind][prev_ind + 1] = max(take, notTake);
}

int solveTab(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }

            int notTake = dp[ind + 1][prev_ind + 1];

            dp[ind][prev_ind + 1] = max(take, notTake);
        }
    }

    return dp[0][-1 + 1];
}

int solveTab2(int *arr, int n)
{
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                continue;
            }

            int possibleAns = dp[j] + 1;
            if (possibleAns > dp[i])
            {
                dp[i] = possibleAns;
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        best = max(best, dp[i]);
    }

    return best;
}

void printLIS(int arr[], int n)
{
    vector<int> dp(n, 1);

    int *hash = new int[n];
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
    }

    int lastindex = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                continue;
            }

            int possibleAns = dp[j] + 1;
            if (possibleAns > dp[i])
            {
                dp[i] = possibleAns;
                hash[i] = j;
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > best)
        {
            best = dp[i];
            lastindex = i;
        }
    }

    // cout << "lastindex : " << lastindex << endl; // to check weather code is correct or not

    int temp[best];

    temp[0] = arr[lastindex];
    int ind = 1;
    while (hash[lastindex] != lastindex)
    {
        lastindex = hash[lastindex];
        temp[ind] = arr[lastindex];
        ind++;
    }

    for (int i = best - 1; i >= 0; i--)
    {
        cout << temp[i] << " ";
    }

    cout << endl;

    // printed hash after dry run to check weather code is correct or not
    // for (int i = 0; i < n; i++)
    // {
    //     cout << hash[i] << " ";
    // }
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return solve(0, n, -1, arr, dp);
    // solveTab(arr, n);
    // solveTab2(arr, n);
    LIS_UsingBinarySearch(arr, n);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Length of LIS : " << longestIncreasingSubsequence(arr, n) << endl;
    cout << "LIS :  ";
    printLIS(arr, n);

    delete[] arr;
    return 0;
}