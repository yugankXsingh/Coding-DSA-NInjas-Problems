#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int partition(int arr[], int si, int ei)
{
    int smaller_count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[si] > arr[i])
        {
            smaller_count++;
        }
    }

    int pivot = si + smaller_count;

    int temp = arr[si];
    arr[si] = arr[pivot];
    arr[pivot] = temp;

    int i = si, j = ei;

    while (i < pivot && j > pivot)
    {
        if (arr[i] < arr[pivot]) // ith element is at correct place.
        {
            i++;
        }
        else if (arr[j] >= arr[pivot]) // jth element is at correct place
        {
            j--;
        }
        else // both ith and jth elements are at wrong positions
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

        return pivot;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void quick_sort(int input[], int si, int ei)
{ // BASE CASE
    if (si >= ei)
    {
        return;
    }

    int pi = partition(input, si, ei);
    quick_sort(input, si, pi - 1);
    quick_sort(input, pi + 1, ei);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int length;
    cin >> length;

    int *input = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    quick_sort(input, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}