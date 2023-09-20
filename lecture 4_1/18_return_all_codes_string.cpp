#include <iostream>
using namespace std;

int getCodes(string input, string output[10000])
{ // BASE CASE
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }

    int firstnum = input[0] - '0';
    char firstchar = firstnum + 'a' - 1;
    char secondchar = '\0';

    string result_1[500];
    string result_2[500];

    int size1 = getCodes(input.substr(1), result_1);
    int size2 = 0;

    if (input[1] != '\0')
    {
        int second = firstnum * 10 + input[1] - 48;

        if (second > 10 && second <= 26)
        {
            secondchar = second + 'a' - 1;
            size2 = getCodes(input.substr(2), result_2);
        }
    }

    // filling output array
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        output[k] = firstchar + result_1[i];
        k++;
    }
    for (int i = 0; i < size2; i++)
    {
        output[k] = secondchar + result_2[i];
        k++;
    }

    return k;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
