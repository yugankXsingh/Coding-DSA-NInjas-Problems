#include <iostream>
using namespace std;

int subsets(int input[], int N, int output[][20])
{
    // BASE CASE
    if (N == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int small_outputSize = subsets(input + 1, N - 1, output);
    // assume the answer to the smaller array has come.

    for (int i = 0; i < small_outputSize; i++)
    {
        output[small_outputSize + i][0] = output[i][0] + 1;
        output[small_outputSize + i][1] = input[0];
        for (int j = 1; j <= output[i][0]; j++)
        {
            output[small_outputSize + i][j + 1] = output[i][j];
        }
    }

    return 2 * small_outputSize;
}

int main()
{
    int input[20], length, output[1000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    int size = subsets(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}