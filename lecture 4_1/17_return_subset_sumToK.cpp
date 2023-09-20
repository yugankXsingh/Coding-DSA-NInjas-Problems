#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    // BASE CASE
    if (n <= 0)
    {
        if (k==0)
        {
            return 1;
        }
    }

    int small_outputSize1 = subsetSumToK(input + 1, n - 1, output, k);        // not picked the 1st element.
    int small_outputSize1 = subsetSumToK(input, n - 1, output, k - input[0]); // not picked the 1st element.
    for (int i = 0; i < small_outputSize1; i++)
    {
    }
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
