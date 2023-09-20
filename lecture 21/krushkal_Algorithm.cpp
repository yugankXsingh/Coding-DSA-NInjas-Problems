#include <iostream>
using namespace std;
#include <algorithm>

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

bool ValueCmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int vertex, int *parents)
{
    if (vertex == parents[vertex])
    { // vertex is the parent of itself
        return vertex;
    }
    return findParent(parents[vertex], parents);
}

int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;
    // n is number of vertices and e is number of Edges
    Edge *input = new Edge[e];      // input will store the graph
    Edge *output = new Edge[n - 1]; // output stores the MST so it can only have n-1 Edges

    // take graph input
    for (int i = 0; i < e; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;

        // create an Edge
        Edge e;
        e.source = v1;
        e.destination = v2;
        e.weight = weight;

        // insert the Edge into the input array
        input[i] = e;
    }

    // sort the input array containing Edges w.r.t their weights
    sort(input, input + e, ValueCmp);

    int *parent = new int[n]; // parent array stored parent of each vertex
    // initialize the parent array --> each vertex is parent of itself
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    // union find algorithm

    int count = 0;
    int i = 0;
    while (count < n - 1)
    {
        Edge currEdge = input[i]; // pick current Edge (min. weighted)

        // vertices forming the currEdge
        int v1 = currEdge.source;
        int v2 = currEdge.destination;

        // top-most parents of vertex v1 and v2
        int v1_parent = findParent(v1, parent);
        int v2_parent = findParent(v2, parent);

        if (v1_parent != v2_parent)
        {
            // v1 and v2 lie in diffrent components
            // insert currEdge into the output array
            output[count] = currEdge;
            count++; // Edge count of MST

            // update the parent array
            parent[v1_parent] = v2_parent;
        }

        i++;
    }

    // print the  MST
    cout << endl
         << "MST:" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        // cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;c
        int first = min(output[i].source, output[i].destination);
        int second = max(output[i].source, output[i].destination);
        cout << first << " " << second << " " << output[i].weight << endl;
    }

    // free space
    delete[] parent;
    delete[] input;
    delete[] output;

    return 0;
}
