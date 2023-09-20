#include <iostream>
using namespace std;

void merge(int a[], int si, int ei)
{
    int size = ei - si + 1;
    int mid = (si + ei) / 2;
    int *output = new int[size]; // dynamically creating new array
    int i = si, j = mid + 1, k = 0;

    while (i <= mid && j <= ei)
    {
        if (a[i] < a[j])
        {
            output[k] = a[i];
            i++;
            k++;
        }
        else
        {
            output[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        output[k] = a[i];
        i++;
        k++;
    }
    while (j <= ei)
    {
        output[k] = a[j];
        j++;
        k++;
    }

    // copying back to original array
    int m = 0;
    for (int i = si; i <= ei; i++)
    {
        a[i] = output[m];
        m++;
    }
}

void merge_sort(int input[], int si, int ei)
{
    // BASE CASE
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;
    merge_sort(input, si, mid);
    merge_sort(input, mid + 1, ei);

    merge(input, si, ei);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int length;
    cin >> length;

    int *input = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    merge_sort(input, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}