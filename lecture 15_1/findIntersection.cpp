#include <iostream>
using namespace std;
#include <unordered_map>

int printIntersection(int *arr1, int *arr2, int N, int M)
{
    unordered_map<int, int> ourmap;

    // create a map corresponding to arr1
    for (int i = 0; i < N; i++)
    {
        if (ourmap.count(arr1[i]) > 0)
        {
            // arr[i] is already present
            ourmap[arr1[i]]++; // increase the freq by 1
            continue;
        }

        // arr1[i] is not present in the map
        ourmap[arr1[i]] = 1; // Now the freq of arr[i] is set to 1
    }

    // traverse over arr2
    for (int i = 0; i < M; i++)
    {
        if (ourmap[arr2[i]] > 0)
        {
            cout << arr2[i] << endl;
            // decrease the freq of the element
            //  because we have printed it once
            ourmap[arr2[i]]--;
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}