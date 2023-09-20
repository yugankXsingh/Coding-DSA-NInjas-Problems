#include <iostream>
using namespace std;

string key[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void print_keypad_code(int num, string output)
{ // BASE CASE
    if (num == 0)
    {
        cout << output << endl;
        return;
    }

    int last_digit = num % 10;
    int small_num = num / 10;
    string options = key[last_digit];

    for (int i = 0; i < options.length(); i++)
    {
        print_keypad_code(small_num, options[i] + output);
    }
}

int main()
{
    int n;
    cin >> n;
    print_keypad_code(n, "");
    return 0;
}