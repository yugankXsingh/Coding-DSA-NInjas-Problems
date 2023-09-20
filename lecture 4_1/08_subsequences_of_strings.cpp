#include <iostream>
using namespace std;
#include <math.h>

int subsequences(string input, string output[])
{                      // BASE CASE
    if (input.empty()) // if the string is empty
    {
        output[0] = "";
        return 1;
    }
    string smallstring = input.substr(1); // a small string starting from index 1 of input string is created
    int smallOutputSize = subsequences(smallstring, output);

    // int j = smallOutputSize;

    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i]; // adding starting character to each string in output array.
    }

    return 2 * smallOutputSize;
}

int main()
{
    string s;
    cin >> s;

    int size = s.size();
    int length = pow(2, size);

    string *out = new string[length];

    int count = subsequences(s, out);

    for (int i = 0; i < count; i++)
    {
        cout << out[i] << endl;
    }

    return 0;
}

////////////////////////SELF////////////////////////////////////////////////////////////////////////////////
// #include <iostream>
// using namespace std;
// #include <math.h>

// int subseq(string input, string output[]) // returns the size of output (array of strings)
// {
//     // BASE CASE
//     if (input.empty())
//     {
//         output[0] = "";
//         return 1;
//     }

//     string smallString = input.substr(1);
//     int small_Output_Size = subseq(smallString, output);

//     for (int i = 0; i < small_Output_Size; i++)
//     {
//         output[i + small_Output_Size] = input[0] + output[i];
//     }

//     return 2 * small_Output_Size;
// }

// int main()
// {
//     string s;
//     cin >> s;

//     int size = s.size();
//     int length = pow(2, size);
//     // create dynamically an output array of strings
//     string *out = new string[length];

//     int count = subseq(s, out);

//     for (int i = 0; i < count; i++)
//     {
//         cout << out[i] << endl;
//     }
//     return 0;
// }