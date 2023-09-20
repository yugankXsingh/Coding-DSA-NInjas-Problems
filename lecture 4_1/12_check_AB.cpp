#include <iostream>
using namespace std;

bool solve(char str[])
{
    if (str[0] == '\0')
    {
        return true;
    }

    bool isTrue;

    if (str[0] == 'a' && (str[1] == '\0' || str[1] == 'a'))
    {
        isTrue = solve(str + 1);
    }
    else if (str[0] == 'a' && str[1] == 'b' && str[2] == 'b')
    {
        isTrue = solve(str + 1);
    }
    else if (str[0] == 'b' && str[1] == 'b' && (str[2] == '\0' || str[2] == 'a'))
    {
        isTrue = solve(str + 1);
    }
    else
    {
        return;
    }
}

bool checkAB(char input[])
{                        // BASE CASE
    if (input[0] != 'a') // if string does not start with a.
    {
        return false;
    }
    else if (input[0] == 'a' and input[1] == '\0') // if string only has a
    {
        return true;
    }
    else if (input[0] == '\0') // if string is empty.
    {
        return true;
    }

    solve(input);
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
