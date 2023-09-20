#include <iostream>
using namespace std;
#include <unordered_map>

int PairSumToZero(int *arr, int N)
{
    unordered_map<int, int> ourmap;
    int pairCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (ourmap.count(arr[i]) > 0)
        {
            // current element is present
            ourmap[arr[i]]++;
        }
        else
        {
            // current element is not present in the map
            ourmap[arr[i]] = 1; // set the freq of current element to 1
        }

        int reqElement = -arr[i];

        if (ourmap.count(-arr[i]) > 0)
        {
            // if required element is present
            pairCount += ourmap[-arr[i]];
            if (arr[i] == 0)
            {
                // if the current element is zero then required element = -arr[i] = -0 = 0 itself
                // so it will increase the pairCount by 1
                // therefore , we need to decrease paircount by 1
                pairCount--;
            }
        }
    }

    return pairCount;
}

int main()
{
    int N;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int ans = PairSumToZero(arr, N);
    cout << ans << endl;
    return 0;
}