#include "bits/stdc++.h"
using namespace std;

// Without visited array
void dfs(int currentNode, vector<vector<int>> &edges, int parentNode)
{
    cout << currentNode << " ";

    for (int neighbour : edges[currentNode])
    {
        if (neighbour != parentNode)
        {
            dfs(neighbour, edges, currentNode);
        }
    }
}

int main()
{
    int n;
    cin >> n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, edges, -1);
    return 0;
}