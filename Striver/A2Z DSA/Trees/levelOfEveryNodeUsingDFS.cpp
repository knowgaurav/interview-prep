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
void levelOfEveryNodeUsingDFS(int currentNode, vector<vector<int>> &edges, int parentNode, vector<int> &levels, int currLevel)
{
    // cout << currentNode << " ";
    levels[currentNode] = currLevel;

    for (int neighbour : edges[currentNode])
    {
        if (neighbour != parentNode)
        {
            levelOfEveryNodeUsingDFS(neighbour, edges, currentNode, levels, currLevel + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());
    vector<int> levels(n, -1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    levelOfEveryNodeUsingDFS(0, edges, -1, levels, 0);

    printVec(levels);

    return 0;
}