#include "bits/stdc++.h"
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, vector<int> &check)
{
    visited[node] = 1;
    pathVisited[node] = 1;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, adj, visited, pathVisited, check))
            {
                return true;
            }
        }
        else if (pathVisited[neighbour])
        {
            return true;
        }
    }

    pathVisited[node] = 0;
    check[node] = 1;
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e)
{
    // Write your code here.
    vector<vector<int>> adj(n, vector<int>());

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    vector<int> visited(n, 0), pathVisited(n, 0), check(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, pathVisited, check);
        }
    }

    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (check[i])
            res.push_back(i);
    }

    return res;
}

// Using Reverse Graph concept and BFS Topological Sorting

class Solution
{
private:
    int V;

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        V = graph.size();
        vector<int> inDegree(V, 0);
        vector<vector<int>> revGraph(V, vector<int>());

        for (int i = 0; i < V; i++)
        {
            for (auto it : graph[i])
            {
                revGraph[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q1;
        vector<bool> flag(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q1.push(i);
        }

        while (!q1.empty())
        {
            int curr = q1.front();
            q1.pop();

            for (int neighbour : revGraph[curr])
            {
                inDegree[neighbour]--;

                if (inDegree[neighbour] == 0)
                {
                    q1.push(neighbour);
                }
            }

            flag[curr] = true;
        }

        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (flag[i])
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

int main()
{

    return 0;
}