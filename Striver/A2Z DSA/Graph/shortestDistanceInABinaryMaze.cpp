#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        queue<pair<int, int>> q1;
        q1.push(source);
        dist[source.first][source.second] = 0;

        if (source == destination)
            return 0;

        vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

        while (!q1.empty())
        {
            pair<int, int> curr = q1.front();
            q1.pop();

            for (auto it : dirc)
            {
                int newX = curr.first + it.first;
                int newY = curr.second + it.second;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    if (grid[newX][newY] == 1 && dist[curr.first][curr.second] + 1 < dist[newX][newY])
                    {

                        dist[newX][newY] = dist[curr.first][curr.second] + 1;
                        q1.push({newX, newY});

                        if (newX == destination.first && newY == destination.second)
                        {
                            return dist[newX][newY];
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}