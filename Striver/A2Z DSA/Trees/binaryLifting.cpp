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
            if (x == -1)
                break;
        }
    }

    return x;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // vector<int> firstParent(n, 0);
    // get1stParent(0, -1, edges, firstParent);

    // for (int ele : firstParent)
    // {
    //     cout << "First parent: " << ele + 1 << endl;
    // }

    // cout << endl;

    // // Get second parent
    // vector<int> secondParent(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     int j = firstParent[i];
    //     if (j != -1)
    //     {
    //         secondParent[i] = firstParent[j];
    //     }
    //     else
    //     {
    //         secondParent[i] = -1;
    //     }
    // }

    // for (int ele : secondParent)
    // {
    //     cout << "Second parent: " << ele + 1 << endl;
    // }

    // cout << endl;

    // // Get fourth parent
    // vector<int> fourthParent(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     int j = secondParent[i];
    //     if (j != -1)
    //     {
    //         fourthParent[i] = secondParent[j];
    //     }
    //     else
    //     {
    //         fourthParent[i] = -1;
    //     }
    // }

    // for (int ele : fourthParent)
    // {
    //     cout << "Fourth parent: " << ele + 1 << endl;
    // }

    // first parent = 2^0th parent
    // second parent = 2^1st parent
    // third parent = 2^2nd parent

    // parents[k][i] = 2^kth parent of i
    vector<vector<int>> parents(log2(n) + 1, vector<int>(n));
    get1stParent(0, -1, edges, parents[0]);

    for (int k = 1; k <= log2(n); k++)
    {
        // find out the 2^kth parent of every node
        // parents[k][i] = 2^kth parent of i
        // parents[k][i] = 2^(k-1)th parent of [2^(k-1)th parent of i]

        for (int i = 0; i < n; i++)
        {
            int intermediate = parents[k - 1][i];
            if (intermediate != -1)
                parents[k][i] = parents[k - 1][intermediate];
            else
                parents[k][i] = -1;
        }
    }

    for (int ele : parents[0])
    {
        cout << "First parent: " << ele + 1 << endl;
    }

    return 0;
}