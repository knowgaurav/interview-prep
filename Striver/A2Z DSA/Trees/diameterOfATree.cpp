#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

void getDistance(int currNode, int parentNode, vector<vector<int>> &edges, vector<int> &res)
{
    if (parentNode != -1)
    {
        res[currNode] = res[parentNode] + 1;
    }
    else
    {
        res[currNode] = 0;
    }

    for (int neighbour : edges[currNode])
    {
        if (neighbour != parentNode)
        {
            getDistance(neighbour, currNode, edges, res);
        }
    }
}

int main()
{
    int n;
    cin >> n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());
    vector<int> distX(n, 0), distY(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // Step 1:
    int X = getRandomNumber(0, n - 1);
    getDistance(X, -1, edges, distX);

    // Step 2:
    int Y = 0;
    for (int i = 0; i < n; i++)
    {
        if (distX[i] > distX[Y])
        {
            Y = i;
        }
    }
    getDistance(Y, -1, edges, distY);

    // Step 3:
    int Z = 0;
    for (int i = 0; i < n; i++)
    {
        if (distY[i] > distY[Z])
        {
            Z = i;
        }
    }

    cout << distY[Z] << endl;

    return 0;
}