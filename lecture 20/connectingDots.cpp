#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<char>> &board, int n, int m, int x, int y, bool **visited, int parentX, int parentY)
{
    visited[x][y] = true;

    int directionArr[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    for (int i = 0; i < 4; i++)
    {
        int newX = x + directionArr[i][0];
        int newY = y + directionArr[i][1];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && (newX != parentX || newY != parentY))
        {
            if (board[newX][newY] == board[x][y])
            {
                if (visited[newX][newY])
                {
                    return true; // Found a cycle
                }
                else
                {
                    if (DFS(board, n, m, newX, newY, visited, x, y))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    bool Cycle = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                if (DFS(board, n, m, i, j, visited, -1, -1))
                {
                    Cycle = true;
                    break;
                }
            }
        }
        if (Cycle)
        {
            break;
        }
    }

    // Clean up memory
    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;

    return Cycle;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}