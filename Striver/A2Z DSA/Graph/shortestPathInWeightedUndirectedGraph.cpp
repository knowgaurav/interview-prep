#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> parent(n + 1, -1), dist(n + 1, 1e9);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        dist[1] = 0;
        parent[1] = 1;
        pq.push({0, 1});

        while (!pq.empty())
        {
            int curr = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[curr])
            {
                int neighbour = it.first;
                int edgeWeight = it.second;

                if (edgeWeight + dis < dist[neighbour])
                {
                    dist[neighbour] = edgeWeight + dis;
                    pq.push({dist[neighbour], neighbour});
                    parent[neighbour] = curr;
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        vector<int> res;
        int node = n;

        while (parent[node] != node)
        {
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(node);

        reverse(begin(res), end(res));

        return res;
    }
};

int main()
{

    return 0;
}