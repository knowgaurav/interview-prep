#include "bits/stdc++.h"
using namespace std;

// Using BFS

class Solution
{
private:
    int m, n;

    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};

    bool isValid(int i, int j)
    {
        if (i >= 0 && i < m && j >= 0 && j < n)
            return true;

        return false;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q1;

        if (grid[0][0] == 0)
        {
            q1.push({0, 0});
            grid[0][0] = 1;
        }

        int lvl = 0;

        while (!q1.empty())
        {
            int size = q1.size();

            while (size--)
            {
                pair<int, int> curr = q1.front();
                q1.pop();

                if (curr.first == m - 1 && curr.second == n - 1)
                    return lvl + 1;

                for (auto dir : dirc)
                {
                    int newX = dir.first + curr.first;
                    int newY = dir.second + curr.second;

                    if (isValid(newX, newY) && grid[newX][newY] == 0)
                    {
                        grid[newX][newY] = 1;
                        q1.push({newX, newY});
                    }
                }
            }

            lvl++;
        }

        return -1;
    }
};

// Using Dijkstra

class Solution
{
    int n;
    typedef pair<int, pair<int, int>> p;

    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}};

    bool isValid(int i, int j)
    {
        if (i >= 0 && i < n && j >= 0 && j < n)
            return true;

        return false;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        n = grid.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        if (grid[0][0] == 0)
        {
            pq.push({0, {0, 0}});
            dist[0][0] = 0;
        }

        while (!pq.empty())
        {
            pair<int, pair<int, int>> curr = pq.top();
            int d = curr.first;
            pq.pop();

            for (auto dir : dirc)
            {
                int newX = dir.first + curr.second.first;
                int newY = dir.second + curr.second.second;

                if (isValid(newX, newY) && grid[newX][newY] == 0)
                {
                    if (d + 1 < dist[newX][newY])
                    {
                        dist[newX][newY] = 1 + d;
                        pq.push({1 + d, {newX, newY}});
                    }
                }
            }
        }

        if (dist[n - 1][n - 1] == INT_MAX)
            return -1;
        return dist[n - 1][n - 1] + 1;
    }
};

int main()
{

    return 0;
}