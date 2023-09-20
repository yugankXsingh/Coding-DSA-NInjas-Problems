#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int getAllWaysHelper(int a, int power, int val)
{
}

int getAllWays(int a, int b)
{
    // Write your code here
    return getAllWaysHelper(a, b, 1);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}