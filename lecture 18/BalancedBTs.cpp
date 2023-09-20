#include <iostream>
using namespace std;
const int MOD = 1000000007;

/////////////////////////////////////////////////////// Recursive /////////////////////////////////////////////////////////////////////

int balancedBTs(int h)
{
    // base case
    if (h == 0 || h == 1)
    {
        return 1;
    }

    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    // 3 cases --> left subtree and right subtree height is h-1
    //  left subtree height is h-1 and right subtree height is h-2
    //  left subtree height is h-2 and right subtree height is h-1

    int temp1 = (int)(((long)(x)*x) % MOD);
    int temp2 = (int)((2 * (long)(x)*y) % MOD);

    int ans = (temp1 + temp2) % MOD;
    return ans;
}

/////////////////////////////////////////////////////// Memoization /////////////////////////////////////////////////////////////////////

int balancedBTs_2_helper(int n, int *arr)
{
    // base case
    if (n <= 1)
    {
        return 1;
    }

    int x, y;

    if (arr[n] != -1)
    {
        return arr[n];
    }

    if (arr[n - 1] != -1)
    {
        x = arr[n - 1];
    }
    else
    {
        x = balancedBTs_2_helper(n - 1, arr);
    }

    if (arr[n - 2] != -1)
    {
        y = arr[n - 2];
    }
    else
    {
        y = balancedBTs_2_helper(n - 2, arr);
    }

    int temp1 = (int)(((long)(x)*x) % MOD);
    int temp2 = (int)((2 * (long)(x)*y) % MOD);

    int ans = (temp1 + temp2) % MOD;
    return ans;
}

int balancedBTs_2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return balancedBTs_2_helper(n, arr);
}

//////////////////////////////////////////////////////// Using iterative Bottom-Up approach ////////////////////////////////////////////////

int balancedBTs_3(int n)
{
    int *arr = new int[n + 1];

    // fill initial vlaues
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int x = arr[i - 1];
        int y = arr[i - 2];

        int temp1 = (int)(((long)(arr[i - 1]) * arr[i - 1]) % MOD);
        int temp2 = (int)((2 * (long)(arr[i - 1]) * arr[i - 2]) % MOD);

        arr[i] = (temp1 + temp2) % MOD;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}