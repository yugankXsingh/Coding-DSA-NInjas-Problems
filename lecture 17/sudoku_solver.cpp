#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, int row, int col, int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {

        // check in that row
        if (board[row][i] == n)
        {
            // number already present in that row
            return false;
        }

        // check column
        if (board[i][col] == n)
        {
            return false;
        }

        // check in the same grid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == n)
        {
            return false;
        }
    }

    return true;
}

bool solve(int board[9][9])
{

    // check for empty spaces
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == 0)
            {
                // empty space found

                for (int p = 1; p <= 9; p++)
                {

                    if (isSafe(p, i, j, board))
                    {
                        // number can be filled at that place
                        board[i][j] = p;

                        // call to solve for next empty space
                        bool ans = solve(board);

                        if (ans == true)
                        {
                            return ans;
                        }
                        else
                        {
                            // solution not found
                            // backtrack
                            board[i][j] = 0;
                        }
                    }
                }

                // no number can pe put at that place
                return false;
            }
        }
    }
}

bool isPossible(int board[9][9])
{

    return solve(board);
}

int main()
{
    // write your code here
    int board[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    if (isPossible(board))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}