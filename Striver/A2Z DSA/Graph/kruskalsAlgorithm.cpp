#include "bits/stdc++.h"
using namespace std;

class DisjointSet
{
private:
    vector<int> size, parent;

public:
    DisjointSet(int N)
    {
        size.resize(N + 1, 0);
        parent.resize(N + 1, 0);

        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (size[uParent] < size[vParent])
        {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else
        {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];

                edges.push_back({wt, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mst = 0;

        for (auto edge : edges)
        {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findParent(u) != ds.findParent(v))
            {
                ds.unionBySize(u, v);
                mst += wt;
            }
        }

        return mst;
    }
};

int main()
{

    return 0;
}