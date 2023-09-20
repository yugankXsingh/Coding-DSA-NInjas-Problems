#include <iostream>
using namespace std;

int staircase(int N)
{
    // BASE CASE
    if (N == 0 || N == 1)
    {
        return 1;
    }
    else if (N == 2)
    {
        return 2;
    }

    int x = staircase(N - 1); // initially took 1 step.
    int y = staircase(N - 2); // initially took 2 steps.
    int z = staircase(N - 3); // initially took 3 steps.

    int total_steps = x + y + z;

    return total_steps;
}

int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
    return 0;
}
