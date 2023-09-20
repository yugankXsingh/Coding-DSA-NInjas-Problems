#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////// Recursive Brute Force /////////////////////////////////////////////////////////////

int solve(int denominations[], int index, int value)
{
    // base case
    if (index == 0)
    {
        // only 1 coin is present
        if (value % denominations[0] == 0)
        {
            // there is a possible ans
            return 1;
        }
        else
        {
            // coins cannot be chosen
            return 0;
        }
    }

    // take case
    int take = 0;
    if (denominations[index] <= value)
    {
        take = solve(denominations, index, value - denominations[index]);
    }

    // notTake case
    int notTake = solve(denominations, index - 1, value);

    return take + notTake;
}

int countWaysToMakeChange(int denominations[], int n, int value)
{
    // Write your code here
    return solve(denominations, n - 1, value);
}

//////////////////////////////////////////////////////////////////////// Memoization /////////////////////////////////////////////////////////////////////////////

int solveMem(int denominations[], int index, int value, int **dp)
{ // base case
    if (index == 0)
    {
        // only 1 coin is present
        if (value % denominations[0] == 0)
        {
            // there is a possible ans
            return 1;
        }
        else
        {
            // coins cannot be chosen
            return 0;
        }
    }

    if (dp[index][value] != -1)
    {
        return dp[index][value];
    }

    // take case
    int take = 0;
    if (denominations[index] <= value)
    {
        take = solveMem(denominations, index, value - denominations[index], dp);
    }

    // notTake case
    int notTake = solveMem(denominations, index - 1, value, dp);

    dp[index][value] = take + notTake;
    return dp[index][value];
}

int countWaysToMakeChange_Mem(int denominations[], int n, int value)
{
    // variables in recursive function are index and value
    // index varies from 0 to (n-1) value and value varies from 0 to the given value
    // hence we need a dp[n][value + 1].

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[value + 1];
        for (int j = 0; j <= value; j++)
        {
            dp[i][j] = -1;
        }
    }

    return solveMem(denominations, n - 1, value, dp);
}

//////////////////////////////////////////////////////////////////////////////////// Bottom-UP appoach //////////////////////////////////////////////////////

int countWaysToMakeChange_Iterative(int denominations[], int n, int value)
{
    // variables in recursive function are index and value
    // index varies from 0 to (n-1) value and value varies from 0 to the given value
    // hence we need a dp[n][value + 1].

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[value + 1];
    }

    // analyse base case

    // dp[i][j] represents no. of ways in which coins up to index ith that can be chosen to achieve the value of j

    // // filling 1st column
    //******************************************** NOT NECESSARY *********************************************************************//
    for (int i = 0; i < n; i++)
    {
        // we have to chose coins upto ith index such that there sum is zero
        dp[i][0] = 1; // there will only be 1 way i.e, not selecting any coins from the denominations array
    }

    // analyse base case
    // if index == 0  i.e, entire 1st row of dp
    for (int j = 0; j <= value; j++)
    {
        dp[0][j] = (value % denominations[0] == 0);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            // notTake case
            int notTake = dp[i - 1][j];

            // take case
            int take = 0;
            if (denominations[i] <= j)
            {
                take = dp[i][j - denominations[i]];
            }

            dp[i][j] = take + notTake;
        }
    }

    // print dp to check dry run
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= value; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n - 1][value];
}

int main()
{
    int n;
    cin >> n;

    int *denominations = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange_Iterative(denominations, n, value) << endl;
    cout << countWaysToMakeChange_Mem(denominations, n, value) << endl;
    cout << countWaysToMakeChange(denominations, n, value) << endl;

    delete[] denominations;
    return 0;
}