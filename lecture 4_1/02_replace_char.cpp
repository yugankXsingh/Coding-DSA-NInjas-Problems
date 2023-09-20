#include <iostream>
using namespace std;
#include <string.h>

void replace_char(char input[], char a, char x)
{ // BASE CASE  //when size of the string is 0.H
    if (input[0] == '\0')
    {
        return;
    }

    replace_char(input + 1, a, x);

    if (input[0] == a)
    {
        input[0] = x;
    }
    else
    {
        return;
    }
}

int main()
{

    char str[100], a, x;
    cin >> str >> a >> x;
    replace_char(str, a, x);
    cout << str;
    return 0;
}