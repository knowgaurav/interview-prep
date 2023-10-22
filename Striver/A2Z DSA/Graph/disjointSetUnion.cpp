#include "bits/stdc++.h"
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);

        // Set parents as self for all the nodes
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find parent
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        // Path compression
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;

        int uRank = rank[u];
        int vRank = rank[v];

        if (uRank < vRank)
        {
            parent[u] = v;
        }
        else if (uRank > vRank)
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;

        int uSize = size[u];
        int vSize = size[v];

        if (uSize < vSize)
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}