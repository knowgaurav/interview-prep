#include "bits/stdc++.h"
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;

        if (rank[uParent] < rank[vParent])
            parent[uParent] = vParent;
        else if (rank[uParent] > rank[vParent])
            parent[vParent] = uParent;
        else
        {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }

    int noOfParents()
    {
        int res = 0;

        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                res++;
            }
        }

        return res;
    }
};

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        DisjointSet ds(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && adj[i][j])
                {
                    ds.unionByRank(i, j);
                }
            }
        }

        return ds.noOfParents();
    }
};

int main()
{

    return 0;
}