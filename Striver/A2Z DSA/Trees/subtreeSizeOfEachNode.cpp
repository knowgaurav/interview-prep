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
int subtreeSizeOfEachNode(int currentNode, vector<vector<int>> &edges, int parentNode, vector<int> &subtreeSize)
{
    int child = 0;
    for (int neighbour : edges[currentNode])
    {
        if (neighbour != parentNode)
        {
            child += subtreeSizeOfEachNode(neighbour, edges, currentNode, subtreeSize);
        }
    }

    subtreeSize[currentNode] = child + 1;

    if (child == 0)
        return 1;
    else
        return child + 1;
}

void subtreeSizeOfEachNode2(int currentNode, vector<vector<int>> &edges, int parentNode, vector<int> &subtreeSize)
{
    for (int neighbour : edges[currentNode])
    {
        if (neighbour != parentNode)
        {
            subtreeSizeOfEachNode(neighbour, edges, currentNode, subtreeSize);
            subtreeSize[currentNode] += subtreeSize[neighbour];
        }
    }

    subtreeSize[currentNode]++;
}

int main()
{
    int n;
    cin >> n; // no of nodes
    vector<vector<int>> edges(n, vector<int>());
    vector<int> subtreeSize(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // subtreeSizeOfEachNode(0, edges, -1, subtreeSize);
    subtreeSizeOfEachNode2(0, edges, -1, subtreeSize);

    printVec(subtreeSize);

    return 0;
}