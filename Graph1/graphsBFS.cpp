//Graphs BFS Traversal
#include <iostream>
#include <queue>
using namespace std;

//BFS order
void print(int **edges, int n, int sv, bool *visited)
{
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while(!pending.empty())
    {
        int curr = pending.front();
        pending.pop();
        cout << curr << " ";

        for(int i=0; i<n; i++)
        {
            if(i == sv)
            {
                continue;
            }

            if(edges[curr][i] && !visited[i])
            {
                visited[i] = true;
                pending.push(i);
            }
        }
    }
}

int main()
{
    int n;
    int e;
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    print(edges, n, 0, visited);

    //Delete all the memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
}