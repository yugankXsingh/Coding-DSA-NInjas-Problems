#include <iostream>
using namespace std;

int binary_search(int input[], int start, int end, int x)
{ // BASE CASE
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    if (input[mid] == x)
    {
        return mid;
    }
    if (x > input[mid])
    {
        int ans1 = binary_search(input, mid + 1, end, x);
        return ans1;
    }
    if (x < input[mid])
    {
        int ans2 = binary_search(input, start, mid - 1, x);
        return ans2;
    }
}

int main()
{
    int n, x;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    int ans = binary_search(arr, 0, n - 1, x);
    cout << ans;
    return 0;
}