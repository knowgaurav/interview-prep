#include "bits/stdc++.h"
using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, st, adj);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    // Write your code here!
    vector<vector<int>> adj(nodes, vector<int>());

    for (auto it : graph)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    vector<bool> visited(nodes, false);
    stack<int> st;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    vector<int> res;

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

// Using BFS - Kahn's Algorithm

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    // Write your code here!
    vector<int> inDegree(nodes, 0);
    vector<vector<int>> adj(nodes, vector<int>());

    for (auto it : graph)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q1;

    for (int i = 0; i < nodes; i++)
    {
        if (inDegree[i] == 0)
        {
            q1.push(i);
        }
    }

    vector<int> res;

    while (!q1.empty())
    {
        int curr = q1.front();
        q1.pop();

        for (int neighbour : adj[curr])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
            {
                q1.push(neighbour);
            }
        }

        res.push_back(curr);
    }

    return res;
}

int main()
{

    return 0;
}