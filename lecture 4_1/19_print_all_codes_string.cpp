#include <iostream>
using namespace std;
#include <string.h>

void helper(string input, string output)
{
    // BASE CASE
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }

    int first_num = input[0] - 48;
    char C1 = first_num + 'a' - 1;

    output = output + C1;

    helper(input.substr(1), output);

    if (input[1] != '\0')
    {
        int second_num = first_num * 10 + input[1] - 48;
        if (second_num >= 10 && second_num <= 26)
        {
           char C2 = second_num + 'a' - 1;
            output = output + C2;
            helper(input.substr(2), output);
        }
    }
}

void printAllPossibleCodes(string input)
{
    string output = "";

    helper(input, output);
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
