#include "bits/stdc++.h"
using namespace std;

void get1stParent(int curr, int parent, vector<vector<int>> &edges, vector<int> &parents)
{
    parents[curr] = parent;

    for (int neighbour : edges[curr])
    {
        if (neighbour != parent)
        {
            get1stParent(neighbour, curr, edges, parents);
        }
    }
}

int kthParent(int x, int k, vector<vector<int>> &parents)
{
    int n = parents[0].size();

    for (int i = 0; i <= log2(n); i++)
    {
        if (k & (1 << i))
        {
            x = parents[i][x];
            if (x == -2)
                break;
        }
    }

    return x;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> edges(n, vector<int>());

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        edges[x].push_back(i);
    }

    // first parent = 2^0th parent
    // second parent = 2^1st parent
    // third parent = 2^2nd parent

    // parents[k][i] = 2^kth parent of i
    vector<vector<int>> parents(log2(n) + 1, vector<int>(n));
    get1stParent(0, -2, edges, parents[0]);

    for (int k = 1; k <= log2(n); k++)
    {
        // find out the 2^kth parent of every node
        // parents[k][i] = 2^kth parent of i
        // parents[k][i] = 2^(k-1)th parent of [2^(k-1)th parent of i]

        for (int i = 0; i < n; i++)
        {
            int intermediate = parents[k - 1][i];
            if (intermediate != -2)
                parents[k][i] = parents[k - 1][intermediate];
            else
                parents[k][i] = -2;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;
        cout << kthParent(x, k, parents) + 1 << endl;
    }

    return 0;
}