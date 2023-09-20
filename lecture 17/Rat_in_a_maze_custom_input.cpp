/*
    Note:
    To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
    This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
    down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int row, int col, int n, vector<vector<int>> arr, vector<vector<bool>> &vis)
{
    // codintion 1
    if (row == n || col == n || row < 0 || col < 0)
    {
        return false;
    }

    // condition 2
    if (vis[row][col] == 1)
    {
        return false;
    }

    // condition 3
    if (arr[row][col] != 1)
    {
        return false;
    }

    // if ((row >= 0 && row < n) && (col >= 0 && col < n) &&
    //     (vis[row][col] == 0) && (arr[row][col] == 1))
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
    return true;
}

void solve(int x, int y, vector<vector<int>> arr, int n, vector<vector<bool>> &vis)
{ // base case
    if (x == n - 1 && y == n - 1)
    {
        // destination is reached
        vis[x][y] = 1;

        // also print the visited matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        vis[x][y] = 0;
        return;
    }

    // 4 possible movements--> D , L , R , U

    vis[x][y] = 1;

    // Down
    if (isPossible(x + 1, y, n, arr, vis))
    {
        solve(x + 1, y, arr, n, vis);
    }

    // Left
    if (isPossible(x, y - 1, n, arr, vis))
    {
        solve(x, y - 1, arr, n, vis);
    }

    // Right
    if (isPossible(x, y + 1, n, arr, vis))
    {
        solve(x, y + 1, arr, n, vis);
    }

    // Up
    if (isPossible(x - 1, y, n, arr, vis))
    {
        solve(x - 1, y, arr, n, vis);
    }

    // backtracking
    vis[x][y] = 0;
}

void paths(vector<vector<int>> arr, int n)
{

    vector<vector<bool>> visited(n, vector<bool>(n, 0)); // initilaise with 0
    if (arr[0][0] == 0)
    {
        return;
    }

    solve(0, 0, arr, n, visited);
    return;
}

int main()
{

    // Write your code here

    vector<vector<int>> input;

    int matrixSize;
    cin >> matrixSize;

    int n = matrixSize;

    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        // traverse over columns of matrix
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }

        // push that vector into the input vector
        input.push_back(v);
    }

    cout << endl;
    paths(input, n);

    return 0;
}
// 1 1 1
// 1 1 0
// 0 1 1
