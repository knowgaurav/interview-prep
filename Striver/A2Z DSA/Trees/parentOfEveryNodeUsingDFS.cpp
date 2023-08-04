#include "bits/stdc++.h"
using namespace std;

void printVec(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

// Without visited array
void parentOfEveryNodeUsingDFS(int currentNode, vector<vector<int>> &edges, int parentNode, vector<int> &parents)
{
    // cout << currentNode << " ";
    parents[currentNode] = parentNode;

    for (int neighbour : edges[currentNode])
    {
        if (neighbour != parentNode)
        {
            parentOfEveryNodeUsingDFS(neighbour, edges, currentNode, parents);
        }
    }
}

int main()
{
    int n;
    cin >> n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());
    vector<int> parents(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    parentOfEveryNodeUsingDFS(0, edges, -1, parents);

    printVec(parents);

    return 0;
}