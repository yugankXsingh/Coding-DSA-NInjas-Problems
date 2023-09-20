#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

vector<int> removeDuplicates(int *arr, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;

    for (int i = 0; i < size; i++)
    {
        if (seen.count(arr[i]) > 0)
        {
            // we have seen this element already
            continue;
        }

        // we haven't seen element yet
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }

    return output;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 3, 9, 10, 9};

    vector<int> ans = removeDuplicates(arr, 14);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }

    return 0;
}