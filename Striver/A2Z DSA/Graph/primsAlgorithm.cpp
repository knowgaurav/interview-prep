#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(ElogV)
        Space Complexity : O(V)
    */

private:
    typedef pair<int, int> P;

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> visited(V, false);
        int sum = 0;

        pq.push({0, 0});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = true;
            sum += wt;

            for (auto neighbour : adj[node])
            {
                if (!visited[neighbour[0]])
                {
                    pq.push({neighbour[1], neighbour[0]});
                }
            }
        }

        return sum;
    }
};

int main()
{

    return 0;
}