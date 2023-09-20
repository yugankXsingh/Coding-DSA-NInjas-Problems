#include <iostream>
using namespace std;

int findDuplicate(int arr[], int size) // contains numbers from 0 to(N - 2).
                                       // Each number is present at least once
{
    // calculate the sum of all elements in the array
    int actual_sum = 0;
    for (int i = 0; i < size; i++)
    {
        actual_sum += arr[i];
    }
    // calculate the sum of numbers from 0 to n-2.
    int sum = 0;
    for (int i = 0; i <= (size - 2); i++)
    {
        sum += i;
    }
    int duplicate = actual_sum - sum;
    return duplicate;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }
        cout << findDuplicate(input, size) << endl;
    }
    return 0;
}
