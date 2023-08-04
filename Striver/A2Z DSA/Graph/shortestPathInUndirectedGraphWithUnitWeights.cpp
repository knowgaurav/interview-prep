#include "bits/stdc++.h"
using namespace std;

/*
    Using Simple BFS -
    Time Complexity : O(V + E)
    Space Complexity : O(V + E)
*/

vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{
    // Write your code here.
    vector<vector<int>> adj(n, vector<int>());

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q1;
    vector<int> dist(n, INT_MAX);

    q1.push(src);
    dist[src] = 0;

    while (!q1.empty())
    {
        int curr = q1.front();
        int wt = dist[curr];
        q1.pop();

        for (int neighbour : adj[curr])
        {
            if (wt + 1 < dist[neighbour])
            {
                dist[neighbour] = wt + 1;
                q1.push({neighbour});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
        }
    }

    return dist;
}

int main()
{

    return 0;
}