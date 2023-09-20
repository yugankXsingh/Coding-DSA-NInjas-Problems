#include <iostream>
using namespace std;
#include <string.h>

void removeX(char input[])
{ // Base Case
    if (strlen(input) == 0)
    {
        return;
    }
    // Recursive call
    removeX(input + 1);

    if (input[0] == 'x')
    {
        // shift all elements towards right
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

int stringLength(char input[])
{
    // BASE CASE
    if (input[0] == '\0')
    {
        return 0;
    }

    // Recursive call
    int small_length = stringLength(input + 1);
    return small_length + 1;
}

int main()
{
    char str[100];
    cin >> str;
    cout << stringLength(str) << endl;
    removeX(str);
    cout << str << endl;
    cout << stringLength(str);
    return 0;
}