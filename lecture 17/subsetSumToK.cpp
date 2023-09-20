#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int size, int target, int index, int CurrSum)
{

    // base case
    if (index == size)
    {
        if (CurrSum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // for each element in array we have 2 choices
    // whether to include them or not

    // include number at current index
    int opt1 = solve(arr, size, target, index + 1, CurrSum + arr[index]);

    // not include
    int opt2 = solve(arr, size, target, index + 1, CurrSum);

    return opt1 + opt2;
}

int subsetSumToK(int arr[], int size, int target)
{
    return solve(arr, size, target, 0, 0);
}

int main()
{

    // write your code here

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, k;
        cin >> N >> k;
        int arr[N];

        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }

        cout << subsetSumToK(arr, N, k) << endl;
    }

    return 0;
}