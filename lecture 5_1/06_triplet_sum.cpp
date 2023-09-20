#include <iostream>
using namespace std;
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pairSum(int *arr, int n, int num)
{
    // sort(arr, arr + n);  // no need to sort the array again.
    int i = 0;
    int j = n - 1;
    int pair_count = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] == num)
        {
            if (arr[i] == arr[j])
            {
                pair_count += ((j - i + 1) * (j - i)) / 2;
                break;
            }
            else
            {
                int count_i = 1;
                int count_j = 1;

                while (arr[i] == arr[i + count_i])
                {
                    count_i++;
                }
                while (arr[j] == arr[j - count_j])
                {
                    count_j++;
                }

                pair_count += count_i * count_j;

                i += count_i;
                j -= count_j;
            }
        }
        else if (arr[i] + arr[j] > num)
        {
            j--;
        }
        else if (arr[i] + arr[j] < num)
        {
            i++;
        }
    }
    return pair_count;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

int tripletSum(int *arr, int n, int num)
{
    // Write your code here
    sort(arr, arr + n);
    int count_tripletSum = 0;

    for (int i = 0; i < n; i++)
    {
        int required_pairSum = num - arr[i];

        int validPairs = pairSum((arr + i + 1), n - (i + 1), required_pairSum);
        count_tripletSum += validPairs;
    }
    return count_tripletSum;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << tripletSum(input, size, x) << endl;

        delete[] input;
    }
    return 0;
}