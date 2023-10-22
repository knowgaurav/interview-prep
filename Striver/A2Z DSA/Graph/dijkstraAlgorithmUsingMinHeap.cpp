#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(ElogV)
    Space Complexity : O(V)
*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int curr = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[curr])
            {
                int neighbour = it[0];
                int nodeWeight = it[1];

                if (dis + nodeWeight < dist[neighbour])
                {
                    dist[neighbour] = dis + nodeWeight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        return dist;
    }
};

int main()
{

    return 0;
}