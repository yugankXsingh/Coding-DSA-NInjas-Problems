#include <iostream>
using namespace std;

int main()
{
    
    return 0;
}

int lcs_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    // Base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Check if ans already exists
    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    // Recursive calls
    if (s[0] == t[0])
    {
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcs_mem(s.substr(1), t, output);
        int b = lcs_mem(s, t.substr(1), output);
        int c = lcs_mem(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }

    // Save your calculation
    output[m][n] = ans;

    // Return ans
    return ans;
}