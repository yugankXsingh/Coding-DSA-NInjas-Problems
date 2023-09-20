#include <iostream>
using namespace std;
#include <unordered_map>

int MaxFreq(int *arr, int N)
{
    unordered_map<int, int> NumFreq;
    for (int i = 0; i < N; i++)
    {
        if (NumFreq.count(arr[i]) > 0)
        {
            // arr[i] is already present
            // increase the frequency of arr[i]
            NumFreq[arr[i]]++;
            continue;
        }

        // arr[i] is not present in hashmap
        // insert it in the map
        NumFreq[arr[i]] = 1; // now the freq. of arr[i] has become 1
    }

    // find max freq into the map
    int maxOccuringNum = 0;
    int maxOccuringFreq = 0;

    for (int i = 0; i < NumFreq.size(); i++)
    {
        // c+ompare the frequencies of current most occuring number
        // with the freq of current number

        if (NumFreq[arr[i]] == maxOccuringFreq)
        {
            // frequency of current most frequent no. and arr[i] are equal
            continue;
        }
        if (NumFreq[arr[i]] > maxOccuringFreq)
        {
            // update the maxoccurring number
            // because freq of arr[i] is greater than current most frequent number

            maxOccuringNum = arr[i];

            // update the max occuring frequency
            maxOccuringFreq = NumFreq[arr[i]];
        }
    }

    return maxOccuringNum;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << MaxFreq(arr, n);

    delete[] arr;
}