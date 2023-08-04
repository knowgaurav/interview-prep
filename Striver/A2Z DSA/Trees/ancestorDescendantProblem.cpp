#include "bits/stdc++.h"
using namespace std;

void dfs(int currNode, int parentNode, vector<vector<int>> &edges, int &counter, vector<int> &inTime, vector<int> &outTime)
{
    inTime[currNode] = counter++;

    for (int neighbour : edges[currNode])
    {
        if (neighbour != parentNode)
        {
            dfs(neighbour, currNode, edges, counter, inTime, outTime);
        }
    }

    outTime[currNode] = counter++;
}

int main()
{
    int n;
    cin >> n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int counter = 1;
    vector<int> inTime(n, 0), outTime(n, 0);

    dfs(0, -1, edges, counter, inTime, outTime);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << inTime[i] << " - " << outTime[i] << endl;
    // }

    int Q = 0;
    cin >> Q;

    while (Q--)
    {
        int X, Y;
        cin >> X >> Y;

        --X;
        --Y;

        if ((inTime[X] < inTime[Y]) && (inTime[Y] < outTime[Y]) && (outTime[Y] < outTime[X]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}