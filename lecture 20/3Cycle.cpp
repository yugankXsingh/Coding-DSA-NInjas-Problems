#include <iostream>
using namespace std;

int CycleCount(int **edges, int n)
{

    int count = 0;
    for (int sv = 0; sv < n; sv++)
    { // for each starting vertex find vertex having edge with starting vertex
        for (int i = 0; i < n; i++)
        {
            if (edges[sv][i] == 1)
            { // now find the vertex having edge with i --> other than the sv
                for (int j = 0; j < n; j++)
                {
                    if (edges[i][j] == 1 && j != sv)
                    {
                        // check weather sv has an edge with j or not
                        if (edges[sv][j] == 1)
                        { // 3 Cycle found!
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count / 6;
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

    cout << CycleCount(edges, n) << endl;

    return 0;
}