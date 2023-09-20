#include <iostream>
using namespace std;
#include <stack>

bool isBalanced(string input)
{
    int n = input.size();
    stack<char> st;

    for (int i = 0; i < n; i++)
    { // if any opening brackets
        if (input[i] == '[' or input[i] == '(' or input[i] == '{')
        {
            st.push(input[i]);
        }
        // for any closing brackets
        else if (input[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (input[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (input[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // ifthe stack is empty then return true
    if (st.empty())
    {
        return true;
    }
}

int main()
{
    string str1 = "{[()]}";
    string str2 = "{[)]]";

    bool ans1 = isBalanced(str1);
    cout << ans1 << endl;

    bool ans2 = isBalanced(str2);
    cout << ans2 << endl;

    return 0;
}