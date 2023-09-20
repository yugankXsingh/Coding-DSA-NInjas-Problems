#include <iostream>
#include <string>
using namespace std;

void returnPermutations(string input, string output)
{
    // BASE CASE
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }

    char first_char = input[0];
    returnPermutations(input.substr(1), first_char + output);

    for (int i = 0; i < output.size(); i++)
    {
        first_char = input[i];

        returnPermutations(input.substr(0, i) + input[0], first_char + output);
    }
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    returnPermutations(input, "");

    return 0;
}
