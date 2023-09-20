#include <iostream>
using namespace std;

string key[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypadCode(int n, string output[])

{
    // Base Case
    if (n == 0 || n == 1)
    {
        output[0] = "";
        return 1;
    }

    int lastDigit = n % 10;
    int smallNumber = n / 10;
    string options = key[lastDigit];
    int smallOutputSize = keypadCode(smallNumber, output);

    for (int i = 0; i < options.length() - 1; i++)
    {
        for (int j = 0; j < smallOutputSize; j++)
        {
            output[j + (i + 1) * smallOutputSize] = output[j];
        }
    }

    int k = 0;

    for (int i = 0; i < options.length(); i++)
    {
        for (int j = 0; j < smallOutputSize; j++)
        {
            output[k] = output[k] + options[i];
            k++;
        }
    }

    return smallOutputSize * (options.length());
}

int main()
{

    int num;
    cin >> num;
    string output[10000];

    int count = keypadCode(num, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}