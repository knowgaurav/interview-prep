#include "bits/stdc++.h"
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n, 0);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;

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
            parent[uParent] = vParent;
            rank[vParent]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // code here
        int n = accounts.size();
        DisjointSet ds(n + 1);
        unordered_map<string, int> mapMailNodes;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                int node = i;
                string email = accounts[i][j];

                if (mapMailNodes.find(email) == mapMailNodes.end())
                {
                    mapMailNodes[email] = i;
                }
                else
                {
                    ds.unionByRank(i, mapMailNodes[email]);
                }
            }
        }

        vector<string> mergedEmails[n];

        for (auto it : mapMailNodes)
        {
            int parent = ds.findParent(it.second);
            string email = it.first;
            mergedEmails[parent].push_back(email);
        }

        vector<vector<string>> res;

        for (int i = 0; i < n; i++)
        {
            if (mergedEmails[i].size() == 0)
                continue;

            sort(begin(mergedEmails[i]), end(mergedEmails[i]));

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (string &s : mergedEmails[i])
            {
                temp.push_back(s);
            }

            res.push_back(temp);
        }

        return res;
    }
};

int main()
{

    return 0;
}