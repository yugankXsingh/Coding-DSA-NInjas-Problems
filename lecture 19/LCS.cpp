#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//////////////////////////////////////////////////////////////// Recusive-Brute-force Approach ////////////////////////////////////////

int LCS(string S, string T)
{
    // Base case
    if (S.size() == 0 || T.size() == 0)
    {
        return 0;
    }

    // case 1: If first character of S and T matches
    if (S[0] == T[0])
    {
        return 1 + LCS(S.substr(1), T.substr(1));
    }

    // Case 2: discard first character from S
    int a = LCS(S.substr(1), T.substr());

    // Case 3: discard first character from T
    int b = LCS(S, T.substr(1));

    // case 4: discard first character from both S and T
    int c = LCS(S.substr(1), T.substr(1)); // --> this call is redundant and is automatically handle. To understand draw recursion tree

    return max(a, max(b, c));

    // Time complexity -->  exponential O(3^string length or 2^ string length)
}

////////////////////////////////////////////////////////////////// Memoization Approach ///////////////////////////////////////////////////////

int LCS_Mem_Helper(string S, string T, int **&dp)
{
    // Base case
    if (S.size() == 0 || T.size() == 0)
    {
        return 0;
    }

    int i = S.length();
    int j = T.length();

    // dp[i][j] will store the LCS of string S with length i and string T of length j
    // check if LCS of string S with length i and string T of length j is already present in dp

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // else calculate the required LCS
    int ans;
    // case 1: If first character of S and T matches
    if (S[0] == T[0])
    {
        ans = 1 + LCS_Mem_Helper(S.substr(1), T.substr(1), dp);
    }
    else
    {
        // Case 2: discard first character from S
        int a = LCS_Mem_Helper(S.substr(1), T.substr(), dp);

        // Case 3: discard first character from T
        int b = LCS_Mem_Helper(S, T.substr(1), dp);

        // case 4: discard first character from both S and T
        int c = LCS_Mem_Helper(S.substr(1), T.substr(1), dp);

        ans = max(a, max(b, c));
    }

    // store the answer in dp for future use
    dp[i][j] = ans;

    return dp[i][j];
    // Time complexity --> O[m*n]
}

int LCS_Mem(string S, string T)
{
    int m = S.length(), n = T.length();

    //  Total number of unique calls will be (m+1)*(n+1)
    // we need a dp array of size (m+1)*(n+1)

    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        // initialize each cell of dp with
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    return LCS_Mem_Helper(S, T, dp);
}

////////////////////////////////////////////////////////// Bottom-Up approach ///////////////////////////////////////////////////////////////////////////

int LCS_DP(string S, string T)
{
    int m = S.length(), n = T.length();

    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
    }

    // fill the first row with zero
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // fill the first column with zero
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    // fill the remaining matrix from left to right -> row by row
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S[m - i] == T[n - j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];

                dp[i][j] = max(a, max(b, c));
            }
        }
    }

    return dp[m][n];

    // Time complexity --> O(m*n)
}

int main()
{
    string S, T;
    cin >> S;
    cin >> T;
    cout << "LCS = " << LCS(S, T) << endl;
    cout << "LCS = " << LCS_Mem(S, T) << endl;
    cout << "LCS = " << LCS_DP(S, T) << endl;
    return 0;
}