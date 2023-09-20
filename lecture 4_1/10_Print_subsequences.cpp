#include <iostream>
using namespace std;

void print_subseq(string input, string output)
{
    // BASE CASE
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    print_subseq(input.substr(1), output);            // output does not includes the 1st character of input string
    print_subseq(input.substr(1), output + input[0]); // output  includes the 1st character of input string
}

int main()
{
    string input;
    cin >> input;
    string output = "";
    print_subseq(input, output);
    return 0;
}