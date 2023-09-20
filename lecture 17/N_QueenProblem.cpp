#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int board[11][11];

bool isPossible(int row, int col, int n)
{
    // check in the same column
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // check in upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // check in upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void N_QueenHelper(int n, int row)
{
    // base case
    if (row == n)
    {
        // we reached some solution
        // print the solution
        // return

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // place the queen all all posiible places and move to the smaller problem
    for (int col = 0; col < n; col++)
    {
        if (isPossible(row, col, n))
        {
            board[row][col] = 1;

            // move to the smaller problem
            N_QueenHelper(n, row + 1);

            // backtracking
            board[row][col] = 0;
        }
    }
    return;
}

void placeN_Queens(int n)
{
    memset(board, 0, 11 * 11 * sizeof(int));

    N_QueenHelper(n, 0);
}

int main()
{
    placeN_Queens(4);
    return 0;
}
