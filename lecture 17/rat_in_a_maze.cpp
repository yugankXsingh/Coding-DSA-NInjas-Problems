#include <bits/stdc++.h>
#include <iostream>
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

void solve(int x, int y, vector<vector<int>> arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path)
{ // base case
    if (x == n - 1 && y == n - 1)
    {
        // destination is reached
        // store the path in ans vector
        ans.push_back(path);
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
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }

    // Left
    if (isPossible(x, y - 1, n, arr, vis))
    {
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }

    // Right
    if (isPossible(x, y + 1, n, arr, vis))
    {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }

    // Up
    if (isPossible(x - 1, y, n, arr, vis))
    {
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
    }

    // backtracking
    vis[x][y] = 0;
}

vector<string> paths(vector<vector<int>> arr, int n)
{

    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0)); // initilaise with 0
    string path = "";
    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main()
{
    vector<vector<int>> input = {{1, 0, 0, 0},
                                 {1, 1, 0, 0},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1}};

    vector<string> ans = paths(input, 4);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
