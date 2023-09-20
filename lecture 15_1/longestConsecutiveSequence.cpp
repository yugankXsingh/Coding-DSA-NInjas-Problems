#include <iostream>
using namespace std;
#include <string>

int main()
{
    // your code goes here
    int T;
    cin >> T;

    for (int i = T; i > 0; i--)
    {
        string str;
        cin >> str;

        int DD = str[0] * 10 + str[1];
        int MM = str[3] * 10 + str[4];

        if (DD <= 31)
        {
            // DD can be a day
            if (DD <= 12)
            {
                // DD can also be month
                if (MM <= 12)
                {
                    // MM can also be a day or a month
                    cout << "BOTH" << endl;
                }
            }
            else if (DD > 12)
            {
                // DD cannot be month
                // hence, DD is a day
                cout << "DD/MM/YYYY" << endl;
            }
            else if (MM > 12)
            {
                // MM cannot be a month
                // MM is a day
                // hence, DD is month
                cout << "MM/DD/YYYY" << endl;
            }
        }
    }
    return 0;
}