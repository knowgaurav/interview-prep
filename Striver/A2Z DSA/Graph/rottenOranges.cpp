#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    int m, n;

    bool isValid(int i, int j)
    {
        if (i >= 0 && i < m && j >= 0 && j < n)
            return true;
        return false;
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int freshOranges = 0, time = 0;

        queue<pair<int, int>> q1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    freshOranges++;
                else if (grid[i][j] == 2)
                    q1.push({i, j});
            }
        }

        if (freshOranges == 0)
            return time;

        vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

        while (!q1.empty())
        {
            int size = q1.size();

            while (size--)
            {
                pair<int, int> curr = q1.front();
                q1.pop();

                for (auto &dir : dirc)
                {
                    int newX = curr.first + dir.first;
                    int newY = curr.second + dir.second;

                    if (!isValid(newX, newY))
                        continue;

                    if (grid[newX][newY] == 1)
                    {
                        freshOranges--;
                        grid[newX][newY] = 2;
                        q1.push({newX, newY});
                    }
                }
            }

            time++;
        }

        return freshOranges == 0 ? --time : -1;
    }
};

class Solution
{
private:
    int m, n;
    vector<vector<int>> visited;

    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1 && visited[i][j] == 0)
            return true;

        return false;
    }

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        m = grid.size(), n = grid[0].size();
        int freshOranges = 0, time = 0;
        visited.resize(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = 2;
                    q1.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }

        vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

        while (!q1.empty())
        {
            pair<int, int> curr = q1.front().first;
            int currTime = q1.front().second;
            q1.pop();

            time = max(time, currTime);

            for (auto dir : dirc)
            {
                int newX = curr.first + dir.first;
                int newY = curr.second + dir.second;

                if (isValid(newX, newY, grid))
                {
                    q1.push({{newX, newY}, currTime + 1});
                    visited[newX][newY] = 2;
                    freshOranges--;
                }
            }
        }

        return freshOranges == 0 ? time : -1;
    }
};

int main()
{

    return 0;
}