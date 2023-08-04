#include "bits/stdc++.h"
using namespace std;

// Using DFS
class Solution
{
private:
    void topoSortUsingDFS(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &inRecursion, stack<int> &st)
    {
        visited[node] = 1;
        inRecursion[node] = 1;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                topoSortUsingDFS(neighbour, adj, visited, inRecursion, st);
            }
            else if (inRecursion[neighbour])
            {
                return;
            }
        }

        inRecursion[node] = 0;
        st.push(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses, vector<int>());

        for (auto &it : prerequisites)
        {
            int to = it[0];
            int from = it[1];

            adj[from].push_back(to);
        }

        vector<int> visited(numCourses, 0), inRecursion(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                topoSortUsingDFS(i, adj, visited, inRecursion, st);
            }
        }

        vector<int> res;

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        if (res.size() < numCourses)
            return {};

        return res;
    }
};

int main()
{

    return 0;
}