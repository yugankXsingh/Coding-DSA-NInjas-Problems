#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

int getCodes(string input, string output[10000])
{

    // BASE CASE

    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }

    int num1 = input[0] - '0';
    char first_char = num1 + 'a' - 1;
    char second_char = '\0';

    string result_1[500];
    string result_2[500];

    int size1 = getCodes(input.substr(1), result_1);
    int size2 = 0;

    if (input[1] != '\0')
    {
        int num2 = num1 * 10 + input[1] - '0';

        if (num2 >= 10 && num2 <= 26)
        {
            second_char = num2 + 'a' - 1;
            size2 = getCodes(input.substr(2), result_2);
        }
    }

    // propulating the code into output array
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        output[k] = first_char + result_1[i];
        k++;
    }

    for (int i = 0; i < size2; i++)
    {
        output[k] = second_char + result_2[i];
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
        cout << output[i] << endl;
    return 0;
}
