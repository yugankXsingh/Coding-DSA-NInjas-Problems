#include <iostream>
using namespace std;
#include <climits>

int findMinVertex(int *weights, int n, bool *visited)
{
    int minValue = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (weights[i] < minValue && visited[i] == false)
        {
            minValue = weights[i];
            minIndex = i;
        }
    }

    return minIndex;
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
            edges[i][j] = -1;
        }
    }

    // take graph input
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int *weights = new int[n]; // stores weight of each vertex
    weights[0] = 0;            // let weight of vertex 0 be minimum
    for (int i = 1; i < n; i++)
    {
        weights[i] = INT_MAX; // let initial weight of each vertex be infinity
    }

    int *parent = new int[n]; // keep track of parent of each vertex
    parent[0] = -1;

    int count = 0;
    while (count < n - 1)
    {
        // pick the vertex with minimum weight
        int minWeight_vertex = findMinVertex(weights, n, visited); // index of minimum weight represents the vertex for that particular weight
        visited[minWeight_vertex] = true;

        // Travel all its unvisited neighbours
        for (int i = 0; i < n; i++)
        {
            if (edges[minWeight_vertex][i] != -1 && !visited[i])
            {
                // check if edge to i through minWeight_Vertex has lower weight or not
                if (weights[i] > edges[minWeight_vertex][i])
                {
                    // weight of edge  is lesser than weight of neighbour
                    // update the weights array
                    weights[i] = edges[minWeight_vertex][i];
                    // also update the parent of i
                    parent[i] = minWeight_vertex;
                }
            }
        }
        count++;
    }

    for (int i = 1; i < n; i++)
    { // 0 ko nhi rkh rhe kyunki wahan tk ki koi edge ni
        cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weights[i] << endl;
    }

    // free space

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete edges;

    return 0;
}

// Time complexty --> O(n^2) --> n = no. of vertices

// for (int i = 1; i < n; i++)
// { // 0 ko nhi rkh rhe kyunki wahan tk ki koi edge ni
//     if (parent[i] < i)
//     {
//         cout << parent[i] << " " << i << " " << weights[i] << endl; // ya edges[parent[i]][i]  ke badle weights[i]
//     }
//     else
//     {
//         cout << i << " " << parent[i] << " " << weights[i] << endl;
//     }
// }