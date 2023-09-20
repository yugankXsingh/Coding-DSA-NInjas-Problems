#include <iostream>
using namespace std;

bool checksequenece(char large[], char *small)
{ // Base case
    if (small[0] == '\0')
    {
        return true;
    }
    if (large[0] == '\0')
    {
        return false;
    }

    if (small[0] == large[0])
    {
        bool is_Present = checksequenece(++large, ++small);
        return is_Present;
    }
    else
    {
        return checksequenece(++large, small);
    }
}

int main()
{
    char large[10000];
    char small[10000];
    cin >> large;
    cin >> small;
    bool x = checksequenece(large, small);

    if (x)
        cout << "true";
    else
        cout << "false";
}
