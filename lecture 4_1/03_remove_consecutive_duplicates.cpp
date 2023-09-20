#include <iostream>
using namespace std;
#include <string.h>

void remove_consecutive_duplicates(char input[])
{ // BASE CASE
    if (input[0] == '\0')
    {
        return;
    }
    // recursive call
    remove_consecutive_duplicates(input + 1);
    if (input[0] == input[1])
    {
        // shift the string by 1 position towards left (including '\0')
        for (int i = 1; i <= strlen(input); i++)
        {
            input[i - 1] = input[i];
        }
    }
    else
    {
        return;
    }
}

int main()
{
    char str[100];
    cin >> str;
    remove_consecutive_duplicates(str);
    cout << str;
    return 0;
}