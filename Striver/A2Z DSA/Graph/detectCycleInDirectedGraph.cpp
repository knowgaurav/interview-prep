#include "bits/stdc++.h"
using namespace std;

bool dfs(int node, vector<bool> &visited, vector<bool> &pathVisited, vector<vector<int>> &adj)
{
    visited[node] = true;
    pathVisited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, visited, pathVisited, adj))
                return true;
        }
        else if (pathVisited[neighbour])
        {
            return true;
        }
    }

    pathVisited[node] = false;
    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> adj(v, vector<int>());

    for (auto it : edges)
    {
        int start = it[0];
        int end = it[1];

        adj[start].push_back(end);
    }

    vector<bool> visited(v, false), pathVisited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, visited, pathVisited, adj))
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}