#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int helper(string A, string B, int siA, int siB)
{
    // base case
    if (siB == B.length())
    { // any charaacter of A is a subsequence that is not present in B
        return 1;
    }
    if (siA == A.length())
    {
        // A is an empty string hence there is no possible answer to this case
        // therefore return INT_MAX
        return 1001;
    }

    // not taking the first character of A
    int option1 = helper(A, B, siA + 1, siB);

    // take the first character of A
    // find index of A[siA] in string B
    int indexB = -1;
    for (int i = siB; i < B.length(); i++)
    {
        if (B[i] == A[siA])
        {
            indexB = i;
            break;
        }
    }

    if (indexB == -1)
    {
        // first character of A is not present in string B
        // hence the shortest subsequence will be this first character itself
        // therefore , return the length 1
        return 1;
    }

    int option2 = helper(A, B, siA + 1, indexB + 1) + 1;

    return min(option1, option2);
}

int solve(string s, string v)
{
    return helper(s, v, 0, 0);
}

///////////////////////////////////////////////////////// MEMOIZATION ///////////////////////////////////////////////////////

int helperMem(string A, string B, int siA, int siB, int **dp)
{
    // base case
    if (siB == B.length())
    { // since B is emtpy
        // any caharacter of A is a subsequence that is not present in B
        return 1;
    }
    if (siA == A.length())
    {
        // A is an empty string hence there is no possible answer to this case
        // therefore return INT_MAX
        return 1001;
    }

    if (dp[siA][siB] != -1)
    {
        return dp[siA][siB];
    }

    // not taking the first character of A
    int option1 = helperMem(A, B, siA + 1, siB, dp);

    // take the first character of A
    // find index of A[siA] in string B
    int indexB = -1;
    for (int i = siB; i < B.length(); i++)
    {
        if (B[i] == A[siA])
        {
            indexB = i;
            break;
        }
    }

    if (indexB == -1)
    {
        // first cahracter of A is not present in string B
        // hence the shortest subsequence will be this first character itself
        // therefore , return the length 1
        return 1;
    }

    int option2 = helperMem(A, B, siA + 1, indexB + 1, dp) + 1;

    int ans = min(option1, option2);
    dp[siA][siB] = ans;
    return ans;
}

int solveMem(string s, string v)
{
    int **dp = new int *[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        dp[i] = new int[v.length()];
        for (int j = 0; j < v.length(); j++)
        {
            dp[i][j] = -1;
        }
    }
    return helperMem(s, v, 0, 0, dp);
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solveMem(s, v) << endl;
    cout << solve(s, v) << endl;
    return 0;
}