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
        size.resize(n + 1, 1);

        // Set parents as self for all the nodes
        for (int i = 0; i <= n; i++)
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

        int upRank = rank[uParent];
        int vpRank = rank[vParent];

        if (upRank < vpRank)
        {
            parent[uParent] = vParent;
        }
        else if (upRank > vpRank)
        {
            parent[vParent] = uParent;
        }
        else
        {
            parent[uParent] = vParent;
            rank[vParent]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;

        int upSize = size[uParent];
        int vpSize = size[vParent];

        if (upSize < vpSize)
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
private:
    int n, m;
    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

    bool isValid(int x, int y)
    {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;

        return false;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        this->n = n;
        this->m = m;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        DisjointSet ds(n * m);
        vector<int> res;
        int cnt = 0;

        for (auto it : operators)
        {
            int x = it[0];
            int y = it[1];

            if (visited[x][y] == 1)
            {
                res.push_back(cnt);
                continue;
            }

            cnt++;
            visited[x][y] = 1;
            int node = (x * m) + y;

            for (auto dir : dirc)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (isValid(newX, newY))
                {
                    int adjNode = (newX * m) + newY;

                    if (visited[newX][newY] == 1)
                    {
                        if (ds.findParent(node) != ds.findParent(adjNode))
                        {
                            ds.unionBySize(node, adjNode);
                            cnt--;
                        }
                    }
                }
            }

            res.push_back(cnt);
        }

        return res;
    }
};

int main()
{

    return 0;
}