#include <iostream>
using namespace std;
#include <algorithm>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pairSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    int pair_count = 0;

    while (i < j)
    {
        if (arr[i] + arr[j] == num)
        {
            if (arr[i] == arr[j])
            {
                pair_count += (j - i) * (j - i + 1) / 2;
                break;
            }
            else
            {
                int count_i = 0;
                int count_j = 0;

                // counting total occurrences of arr[i] and arr[j]

                for (int k = 0; k < n; k++)
                {
                    if (arr[k] == arr[i])
                    {
                        count_i++;
                    }
                    else if (arr[k] == arr[j])
                    {
                        count_j++;
                    }
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

        cout << pairSum(input, size, x) << endl;

        delete[] input;
    }
    return 0;
}