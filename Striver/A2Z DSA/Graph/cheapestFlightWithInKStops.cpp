#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(E*N) + O(E);
        Space Complexity : O(V+E)
    */

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adjL(n, vector<pair<int, int>>());

        for (auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adjL[u].push_back({v, d});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q1;
        q1.push({src, 0});
        dist[src] = 0;

        int steps = 0;

        while (!q1.empty() && steps <= k)
        {
            int size = q1.size();

            while (size--)
            {
                pair<int, int> curr = q1.front();
                q1.pop();

                for (auto neighbour : adjL[curr.first])
                {
                    if (curr.second + neighbour.second < dist[neighbour.first])
                    {
                        dist[neighbour.first] = curr.second + neighbour.second;
                        q1.push({neighbour.first, curr.second + neighbour.second});
                    }
                }
            }

            steps++;
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};

int main()
{

    return 0;
}