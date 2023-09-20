#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/////////////////////////////////////////////////////////////// Recursive solution ///////////////////////////////////////////////////////

int editDistance(string s, string t)
{
    // base case
    if (s.size() == 0)
    {
        return t.size();
    }
    if (t.size() == 0)
    {
        return s.size();
    }

    // first character matches
    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }

    // insert a charcter in s
    int insertAns = 1 + editDistance(s, t.substr(1));
    // replace a character of s
    int replaceAns = 1 + editDistance(s.substr(1), t.substr(1));
    // delete a character of s
    int deleteAns = 1 + editDistance(s.substr(1), t);

    int ans = min(insertAns, min(replaceAns, deleteAns));
    return ans;

    // Time Complexity --> O(3^n) where n is length if string
}

////////////////////////////////////////////////////////////////// Memoization /////////////////////////////////////////////////////////

int editDistance_Mem_helper(string s, string t, int **dp)
{ // base case
    if (s.size() == 0)
    {
        return t.size();
    }
    if (t.size() == 0)
    {
        return s.size();
    }

    int i = s.size();
    int j = t.size();

    // check if ans for string s of size i and string t of size j is present in the dp array
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // first character matches
    if (s[0] == t[0])
    {
        return editDistance_Mem_helper(s.substr(1), t.substr(1), dp);
    }

    // insert a charcter in s
    int insertAns = 1 + editDistance_Mem_helper(s, t.substr(1), dp);
    // replace a character of s
    int replaceAns = 1 + editDistance_Mem_helper(s.substr(1), t.substr(1), dp);
    // delete a character of s
    int deleteAns = 1 + editDistance_Mem_helper(s.substr(1), t, dp);

    int ans = min(insertAns, min(replaceAns, deleteAns));
    // store this ans for future use
    dp[i][j] = ans;

    return dp[i][j];
    // Time Complexity --> O(m*n)
}

int editDistance_Mem(string s, string t)
{
    int m = s.size(), n = t.size();
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    return editDistance_Mem_helper(s, t, dp);
}

////////////////////////////////////////////////////////////////////// Iterative Bottom-up Approach //////////////////////////////////////

int editDistance_iterative(string s, string t)
{
    int m = s.size(), n = t.size();
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
    }

    // fill top row
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    // fill first column
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }

    // fill the remaining dp
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int x = dp[i - 1][j - 1];
                int y = dp[i - 1][j];
                int z = dp[i][j - 1];

                dp[i][j] = min(x, min(y, z)) + 1;
            }
        }
    }

    return dp[m][n];
    // Time Complexity --> O(m*n)
}

///////////////////////////////////////////////////////////////////////////// optimizing space ////////////////////////////////////////////////////////////
// TODO

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;

    cout << editDistance_iterative(str1, str2) << endl;
    cout << editDistance_Mem(str1, str2) << endl;
    // cout << editDistance_spaceOptimized(str1, str2) << endl; --> TODO
    cout << editDistance(str1, str2) << endl;
    return 0;
}