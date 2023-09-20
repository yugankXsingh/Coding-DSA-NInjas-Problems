#include <bits/stdc++.h>
using namespace std;

#define Mod 1000000000007

//////////////////////////////////////////// recursive solution /////////////////////////////////////////////////////
int countWays(int n)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    int x = countWays(n - 1);
    int y = countWays(n - 2);
    int z = countWays(n - 3);

    int totalWays = x + y + z;
    return totalWays;
}

/////////////////////////////////////////////////// recursion + Memoization ///////////////////////////////////////////////////////

int countWays_helper(int n, int *arr)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    // check if output for n is already calculated
    if (arr[n] != -1)
    {
        return arr[n];
    }

    int totalWays = countWays_helper(n - 1, arr) + countWays_helper(n - 2, arr) + countWays_helper(n - 3, arr);

    // store the output for current value of n into arr
    arr[n] = totalWays;

    return arr[n];
}

int countWays_2(int n)
{
    int *arr = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return countWays_helper(n, arr);
}

////////////////////////////////////////////////////////// Using iterative method --> bottom-Up approach ///////////////////////////////////////////////////

int countWays_3(int n)
{
    int *arr = new int[n + 1];

    // arr[i] --> it holds number of ways in which ith step can be reached from the 0th step
    // fill in the initial values

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = ((arr[i - 1] % Mod + arr[i - 2] % Mod) % Mod + arr[i - 3] % Mod) % Mod;
    }

    return arr[n];
}

int main()
{
    // take input from the user.
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int ans = countWays(n);
        cout << "Using recursive approach = " << ans % Mod << endl;
        ans = countWays_2(n);
        cout << "Using recursive + Memoization approach = " << ans % Mod << endl;
        ans = countWays_3(n);
        cout << "Using bottom-UP approach = " << ans % Mod << endl;
    }
    return 0;
}