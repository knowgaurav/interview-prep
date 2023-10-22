#include "bits/stdc++.h"
using namespace std;

/*
    Kosaraju's Algorithm :
    Time Complexity : O(V+E)
    Space Complexity : O(V+E)
*/

class Solution
{
private:
    vector<int> visited;

    void dfs(int node, vector<vector<int>> &adj, vector<int> &sortedOrder)
    {
        visited[node] = 1;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adj, sortedOrder);
            }
        }

        sortedOrder.push_back(node);
    }

    void dfs2(int node, vector<vector<int>> &adj)
    {
        visited[node] = 1;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs2(neighbour, adj);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<int> sortedOrder;
        visited.resize(V + 1, 0);
        vector<vector<int>> reversedAdj(V + 1, vector<int>());

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, sortedOrder);
            }
        }

        // for(int i=0; i<V; i++){
        //     cout << sortedOrder[i] << " ";
        // }

        // cout << endl;

        for (int i = 0; i < V; i++)
        {
            for (int node : adj[i])
            {
                reversedAdj[node].push_back(i);
            }
        }

        fill(begin(visited), end(visited), 0);
        int res = 0;
        reverse(sortedOrder.begin(), sortedOrder.end());

        for (int i = 0; i < V; i++)
        {
            if (!visited[sortedOrder[i]])
            {
                res++;
                dfs2(sortedOrder[i], reversedAdj);
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}