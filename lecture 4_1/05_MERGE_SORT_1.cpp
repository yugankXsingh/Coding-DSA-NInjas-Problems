#include <iostream>
using namespace std;

void merge(int A[], int sizeA, int B[], int sizeB, int output[])
{
    int i = 0; // index count for A
    int j = 0; // index count for B
    int k = 0; // index count for C

    while (i < sizeA && j < sizeB)
    {
        if (A[i] < B[j])
        {
            output[k] = A[i];
            i++;
            k++;
        }
        else
        {
            output[k] = B[j];
            j++;
            k++;
        }
    }

    while (i < sizeA)
    {
        output[k] = A[i];
        i++;
        k++;
    }
    while (j < sizeB)
    {
        output[k] = B[j];
        j++;
        k++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mergeSort(int input[], int size)
{
    // BASE CASE
    if (size <= 1)
    {
        return;
    }

    int part1[500];
    int part2[500];

    int mid = (size / 2);
    int size1 = mid;
    int size2 = size - mid;

    // Filling part1
    int i;
    for (i = 0; i < mid; i++)
    {
        part1[i] = input[i];
    }

    // Filing part2
    int k = 0;
    for (i = mid; i < size; i++)
    {
        part2[k] = input[i];
        k++;
    }

    // sorting both arrays individually
    mergeSort(part1, size1);
    mergeSort(part2, size2);

    // now merging both sorted arrays together
    merge(part1, size1, part2, size2, input);
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

    mergeSort(input, length);

    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}