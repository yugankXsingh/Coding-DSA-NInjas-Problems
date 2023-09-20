#include <iostream>
using namespace std;
#include <climits>

int shortestDistance(int *distance, int n, bool *visited)
{
    int shortestDistance = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (shortestDistance == -1 || distance[i] < distance[shortestDistance]))
        {
            shortestDistance = i;
        }
    }

    return shortestDistance;
}

void Dijkstras(int **edges, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX; // let initial distance from source be infinity
    }

    distance[0] = 0; // let 0 be source vertex hence distance of 0 from itself is 0

    for (int i = 0; i < n; i++)
    {
        // find vertex with minimum distance from source
        int minDistance_Vertex = shortestDistance(distance, n, visited);
        visited[minDistance_Vertex] = true; // mark this vertex as visited

        // explore its all the unvisited neighbours
        for (int j = 0; j < n; j++)
        {
            if (edges[minDistance_Vertex][j] != -1 && !visited[j])
            { // unvisited neighbour found
                int possibleDistance = distance[minDistance_Vertex] + edges[minDistance_Vertex][j];
                if (possibleDistance < distance[j])
                {
                    // we found a better distance to j
                    // update the distance array
                    distance[j] = possibleDistance;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    // the shortest distances for all vertices from the source are now stored in the distance array

    // print
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    delete[] visited;
    delete[] distance;
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

    cout << "vertices and their corresponding shortest distaces from the source are : " << endl;

    Dijkstras(edges, n);

    // free space
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete edges;

    return 0;
}

// Time complexity --> O(n^2) --> n = number of vertices