#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = true;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (dfs(neighbour, node, adj, visited))
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};

class Solution
{

    /*
        Using BFS
        Time Complexity : O(V + 2E)
        Space Complexity : O(V)
    */

private:
    vector<bool> visited;

    bool bfs(int node, vector<int> adj[])
    {
        queue<pair<int, int>> q1;
        q1.push({node, -1});
        visited[node] = true;

        while (!q1.empty())
        {
            int curr = q1.front().first;
            int parent = q1.front().second;
            q1.pop();

            for (int neighbour : adj[curr])
            {
                if (!visited[neighbour])
                {
                    q1.push({neighbour, curr});
                    visited[neighbour] = true;
                }
                else if (neighbour != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        visited.resize(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfs(i, adj))
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}