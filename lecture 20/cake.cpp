#include <iostream>
#include <vector>
using namespace std;

bool isDirValid(int x, int y, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

int DFS(vector<vector<int>> &cake, int n, int x, int y, bool **visited)
{

    // mark current 1 as visited
    visited[x][y] = true;

    int directionArr[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // four possible directions

    int largestPiece = 0;

    // check in all 4 possible directions
    for (int i = 0; i < 4; i++)
    {
        int newX = x + directionArr[i][0];
        int newY = y + directionArr[i][1];

        // check if direction is  valid
        if (isDirValid(newX, newY, n))
        {
            // check if 1 is present at newX, newxY or not
            if (cake[newX][newY] == 1)
            {
                // check if it is visited or not
                if (!visited[newX][newY])
                {
                    largestPiece += DFS(cake, n, newX, newY, visited);
                }
            }
        }
    }

    return largestPiece + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // Write your code here
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    int largestPiece = 0;

    // find 1 in the cake
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                int ans = DFS(cake, n, i, j, visited);
                largestPiece = max(ans, largestPiece);
            }
        }
    }

    return largestPiece;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}