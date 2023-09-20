#include <iostream>
using namespace std;

int fibo(int n)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    int n1 = fibo(n - 1);
    int n2 = fibo(n - 2);

    return n1 + n2;
    // time complexity --> O(2^n);
}

int fibo_2Helper(int n, int *ans)
{

    // Base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    // check if nth number is present in ans or not
    if (ans[n] != -1)
    {
        // number is present
        return ans[n];
    }
    else
    {
        // number is not present
        int n1 = fibo_2Helper(n - 1, ans);
        int n2 = fibo_2Helper(n - 2, ans);

        // calculate nth number
        int num = n1 + n2;
        // save this number in the ans array
        ans[n] = num;

        // return nth number
        return ans[n];
        // time complexity --> O(n);
    }

    // this is called Memoization
    //  top-bottom approach
}

int fibo_2(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return fibo_2Helper(n, ans);
}

int fibo_3(int n)
{
    int *ans = new int[n + 1];

    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];

    // this approach is called dynamic programming
    // it is a bottom uo approach
}

int main()
{
    cout << fibo_2(0) << fibo_2(1) << fibo_2(2) << fibo_2(3) << fibo_2(4) << fibo_2(5) << fibo_2(6) << endl;
    cout << fibo_3(0) << fibo_3(1) << fibo_3(2) << fibo_3(3) << fibo_3(4) << fibo_3(5) << fibo_3(6);
    return 0;
}