#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne_recursive(int n)
{
    // Write your code here
    // base case
    if (n == 1)
    {
        return 0;
    }

    // find steps for each of the options available

    int count1;
    int count2 = INT_MAX;
    int count3 = INT_MAX;

    count1 = countMinStepsToOne_recursive(n - 1);
    if (n % 2 == 0)
    {
        count2 = countMinStepsToOne_recursive(n / 2);
    }
    if (n % 3 == 0)
    {
        count3 = countMinStepsToOne_recursive(n / 3);
    }

    // return the minimum possible count

    return min(count1, min(count2, count3)) + 1;

    // Time complexity : O(2^n)
    // Note --> O(3^n) will not be the time complexity
    // as on an average only two calls will be made for each function call
}

////////////////////////////////////////////////////////////// Using Memoization //////////////////////////////////////////////////////////////

int countMinStepsToOne_helper(int n, int *ans)
{
    // Write your code here
    // base case
    if (n == 1)
    {
        return 0;
    }

    // check weather min steps for n are already present in the ans array
    if (ans[n] != -1)
    {
        return ans[n];
    }

    // min steps were for n were not present in the ans array
    // find steps for each of the options available

    int count1;
    int count2 = INT_MAX;
    int count3 = INT_MAX;

    count1 = countMinStepsToOne_helper(n - 1, ans);
    if (n % 2 == 0)
    {
        count2 = countMinStepsToOne_helper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        count3 = countMinStepsToOne_helper(n / 3, ans);
    }

    // store these min steps inside the ans array on the corresponding index

    int minSteps = min(count1, min(count2, count3)) + 1;

    ans[n] = minSteps;

    // return min steps
    return ans[n];
}

int countMinStepsToOne(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    return countMinStepsToOne_helper(n, ans);

    // Time complexity : O(n)
}

////////////////////////////////////// Using Dyanmic Programming /////////////////////////////////////////////////////////////////////////////

int countMinStepsToOne_iterative(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    arr[0] = -1;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;

        if (i % 2 == 0)
        {
            // divisible by 2
            int newNum = i / 2;
            x = arr[newNum]; // --> stored the min steps from newNum to 1
        }

        if (i % 3 == 0)
        {
            // divisible by 3
            int newNum = i / 3;
            y = arr[newNum]; // -->stored the min steps from newNum to 1
        }

        int newNum = i - 1;
        z = arr[newNum]; //--> stored the min steps from newNum to 1

        // store the steps required from i to 1;

        arr[i] = min(x, min(y, z)) + 1;
    }

    return arr[n];

    // Time complexity : O(n)
}

int main()
{
    int n;
    cin >> n;
    cout << "Min. steps to " << n << " are = " << countMinStepsToOne(n) << endl;
    cout << "Min. steps to " << n << " are = " << countMinStepsToOne_recursive(n) << endl;
    cout << "Min. steps to " << n << " are = " << countMinStepsToOne_iterative(n);
    return 0;
}