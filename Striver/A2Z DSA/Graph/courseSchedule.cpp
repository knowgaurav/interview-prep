#include "bits/stdc++.h"
using namespace std;

// Using DFS & Cycle Detection

class Solution
{
private:
    bool checkCycleDFS(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &inRecursion)
    {
        visited[node] = 1;
        inRecursion[node] = 1;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (checkCycleDFS(neighbour, adj, visited, inRecursion))
                    return true;
            }
            else if (inRecursion[neighbour] == 1)
            {
                return true;
            }
        }

        inRecursion[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses, vector<int>());

        for (auto &it : prerequisites)
        {
            int to = it[0];
            int from = it[1];

            adj[from].push_back(to);
        }

        vector<int> visited(numCourses, 0), inRecursion(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && checkCycleDFS(i, adj, visited, inRecursion))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}