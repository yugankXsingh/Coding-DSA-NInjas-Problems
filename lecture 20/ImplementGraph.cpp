#include <iostream>
using namespace std;
#include <queue>
#include <unordered_map>

/////////////////////////////////////////////////////////// Depth-first search /////////////////////////////////////////////////////

void print_DFS(int **edges, int n, int sv, bool *visited) // sv --> starting vertex
{
    cout << sv << " ";
    // we have visited that sv so update the visited array
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (visited[i] == true)
            {
                continue;
            }
            print_DFS(edges, n, i, visited);
        }
    }
}

/////////////////////////////////////////////////////////// Breadth-first search /////////////////////////////////////////////////////

void print_BFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertex;
    pendingVertex.push(sv);

    while (!pendingVertex.empty())
    {
        int currentVertex = pendingVertex.front();
        cout << currentVertex << " ";

        // update the visited array
        visited[currentVertex] = true;

        // insert each edge of first into the pendingVertexueue
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }

            if (edges[currentVertex][i] == 1)
            {
                if (visited[i])
                {
                    continue;
                }
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
        pendingVertex.pop();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_DFS(edges, n, i, visited);
        }
    }

    delete[] visited;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_BFS(edges, n, i, visited);
        }
    }

    delete[] visited;
}

////////////////////////////////////////////////////////////// GET PATH ////////////////////////////////////////////////////////////////

vector<int> *getPathHelper(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *output = new vector<int>();
        output->push_back(ev);
        return output;
    }

    visited[sv] = true;

    // check for each vertex having edge with sv
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            vector<int> *smallOutput = getPathHelper(edges, n, i, ev, visited);
            if (smallOutput != NULL)
            {
                // we found a path
                smallOutput->push_back(sv);
                return smallOutput;
            }
        }
    }

    // sv have no path to ev
    return NULL;
}

vector<int> *getPath(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int> *output = getPathHelper(edges, n, sv, ev, visited);
    delete[] visited;
    return output;
}

//////////////////////////////////////////////////////////// GET PATH BFS  //////////////////////////////////////////////////////////////

vector<int> *getPathBFS_Helper(int **edges, int n, int sv, int ev, bool *visited)
{
    unordered_map<int, int> ourmap;
    queue<int> pendingVertex;
    pendingVertex.push(sv);

    int currVertex = sv;
    visited[currVertex] = true;

    while (!pendingVertex.empty())
    {
        currVertex = pendingVertex.front();
        pendingVertex.pop();

        if (currVertex == ev)
        {
            // path found
            break;
        }

        for (int i = 0; i < n; i++)
        {
            if (edges[currVertex][i] && !visited[i])
            {
                pendingVertex.push(i);
                ourmap[i] = currVertex; // because currVeryex pushed i
                visited[i] = true;
            }
        }
    }

    vector<int> *path = new vector<int>();
    // push ev into the path
    if (currVertex == ev)
    {
        path->push_back(ev);
    }
    else
    {
        // no path exists
        return NULL;
    }

    while (ev != sv)
    {
        path->push_back(ourmap[ev]);
        ev = ourmap[ev];
    }

    return path;
}

vector<int> *getPathBFS(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int> *output = getPathBFS_Helper(edges, n, sv, ev, visited);
    delete[] visited;
    return output;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n, e; // n-> no of vertices , e-> number of edges

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

    cout << "DFS : ";
    DFS(edges, n);
    cout << endl
         << "BFS : ";
    BFS(edges, n);

    int sv, ev;
    cin >> sv >> ev;

    vector<int> *path = getPath(edges, n, sv, ev);

    cout << "Path Using DFS : ";

    if (path != NULL)
    {
        for (int i = 0; i < path->size(); i++)
        {
            cout << path->at(i) << " ";
        }
    }
    else
    {
        cout << "No path exists !" << endl;
    }

    cout << endl
         << "Path Using BFS : ";

    vector<int> *pathBFS = getPathBFS(edges, n, sv, ev);

    if (pathBFS != NULL)
    {
        for (int i = 0; i < pathBFS->size(); i++)
        {
            cout << pathBFS->at(i) << " ";
        }
    }
    else
    {
        cout << "No path exists !" << endl;
    }

    // free up memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete path;
    delete pathBFS;

    return 0;
}