#include <iostream>
#include <vector>
using namespace std;

bool isValidDirection(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool DFS(vector<vector<char>> &board, int n, int m, int x, int y, int index, bool **visited, string word)
{
    if (index == 11)
    { // last index of word
        return true;
    }

    visited[x][y] = true; // mark current position as visited

    bool found = false;

    // check in all 8 possible directions

    int directionArray[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}};

    for (int i = 0; i < 8; i++)
    {
        int newX = x + directionArray[i][0];
        int newY = y + directionArray[i][1];

        // check if the direction is valid or not
        if (isValidDirection(newX, newY, n, m))
        {
            // check if character at newX , newY matches the required character
            if (board[newX][newY] == word[index])
            {
                // check if this character has already been visited on not
                if (!visited[newX][newY])
                {
                    found = DFS(board, n, m, newX, newY, index + 1, visited, word);
                }
            }
        }
    }
    // after checking in all directions
    visited[x][y] = false;
    return found;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    // Write your code here

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    string word = "CODINGNINJA";

    bool found = false;

    // find character 'C'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                // found 'C'
                found = DFS(board, n, m, i, j, 1, visited, word);
                if (found)
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
    }
    return found;
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

    cout << (hasPath(board, n, m) ? 1 : 0);
}