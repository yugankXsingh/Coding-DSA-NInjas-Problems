#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

void DFS(int **edges, int n, int sv, vector<int> &component, bool *visited)
{
    visited[sv] = true;
    component.push_back(sv);

    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            DFS(edges, n, i, component, visited);
            visited[i] = true;
        }
    }
}

vector<vector<int>> ALLcomponents(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<vector<int>> output;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            DFS(edges, n, i, component, visited);

            if (component.size() != 0)
            {
                output.push_back(component);
            }
        }
    }

    return output;
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

    vector<vector<int>> components = ALLcomponents(edges, n);

    // number of islands = number of components
    cout << "Number of islands : " << components.size() << endl;

    for (int i = 0; i < components.size(); i++)
    {
        sort(components[i].begin(),
             components[i].end()); // sorting individual vectors
        for (int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}