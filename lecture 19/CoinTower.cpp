#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
    int *dp = new int[n + 1];

    // dp[i] will store the winner for i number of coins

    if (n == x || n == 1 || n == y)
    {
        return "Beerus";
    }

    // Beerus always makes the first move
    // let's represent Beerus' victory with 1 and Whis victory with 0
    dp[1] = 1;
    dp[x] = 1;
    dp[y] = 1;

    for (int i = 2; i <= n; i++)
    {
        // Make the first move

        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;

        ans1 = dp[i - 1];

        if (i - x >= 1)
        {
            ans2 = dp[i - x];
        }

        if (i - y >= 1)
        {
            ans3 = dp[i - y];
        }

        if (ans1 == 0 || ans2 == 0 || ans3 == 0)
        { // If Beerus is losing at any one of the following states
          // then he will send Whis to that state and win the game
            dp[i] = 1;
        }
        else
        {
            // Beerus is winning at all the states
            // Since it will be Whis' chance to make a move hence Whis will win from this state
            dp[i] = 0;
        }
    }

    if (dp[n] == 1)
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}