#include <iostream>
using namespace std;

void DFS(int **edges, int n, bool *visited, int sv)
{
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            DFS(edges, n, visited, i);
            visited[i] = true;
        }
    }
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    DFS(edges, n, visited, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }

    delete[] visited;
    return true;
}

int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    if (isConnected(edges, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}