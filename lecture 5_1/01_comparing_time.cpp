
#include <iostream>
using namespace std;
#include <sys/time.h>

long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = 0;

    int *temp = new int[1000];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i];
            i++;
        }
        else if (arr[j] < arr[i])
        {
            temp[k++] = arr[j];
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i];
        i++;
    }
    while (j <= end)
    {
        temp[k++] = arr[j];
        j++;
    }

    // copying back to arr
    k = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[k++];
    }
    delete[] temp;
}

void mergesort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{
    int n;
    for (n = 10; n <= 1000000; n *= 10)
    {
        int *arr = new int[n];
        long starttime, endtime;
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - 1;
        }

        starttime = getTimeinMicroSeconds();
        mergesort(arr, 0, n - 1);
        endtime = getTimeinMicroSeconds();

        cout << "Merge sort n = " << n << "time = " << endtime - starttime << endl;
    }
    return 0;
}