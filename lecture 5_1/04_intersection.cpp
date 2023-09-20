#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int si, int ei)
{
    int size = ei - si;
    int mid = (si + ei) / 2;
    int *temp = new int[size];
    int i = si;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j < ei)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    int m = 0;
    for (i = si; i <= ei; i++)
    {
        arr[i] = temp[m];
        m++;
    }
    delete[] temp;
}

void merge_sort(int input[], int start, int end)
{ // Base Case
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    merge_sort(input, start, mid);
    merge_sort(input, mid + 1, end);

    merge(input, start, end);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void intersection(int arr1[], int arr2[], int n, int m)
{
    merge_sort(arr1, 0, n - 1);
    merge_sort(arr2, 0, m - 1);

    // Both arrays have been sorted
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int size1, size2;

        cin >> size1;
        int *input1 = new int[size1];

        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        cin >> size2;
        int *input2 = new int[size2];

        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        intersection(input1, input2, size1, size2);

        delete[] input1;
        delete[] input2;

        cout << endl;
    }

    return 0;
}