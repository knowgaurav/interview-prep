#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Brute Force - Using DFS
        Time Complexity = O(7^(n^2))
        Space Complexity = O(n^2)
    */

private:
    int n;
    int res = INT_MAX;

    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};

    bool isSafe(int i, int j, vector<vector<int>> &grid)
    {
        return i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == 0;
    }

    void helper(int i, int j, int cellsVisited, vector<vector<int>> &grid)
    {
        if (i == n - 1 and j == n - 1)
        {
            res = min(res, cellsVisited);
            return;
        }

        grid[i][j] = 2;

        for (auto dir : dirc)
        {
            int newX = i + dir.first;
            int newY = j + dir.second;

            if (isSafe(newX, newY, grid))
            {
                helper(newX, newY, cellsVisited + 1, grid);
            }
        }

        grid[i][j] = 0;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        // i, j, cellsVisited, grid
        helper(0, 0, 1, grid);

        if (res == INT_MAX)
            return -1;

        return res;
    }
};

class Solution
{

    /*
        Optimal Solution - Using BFS
        Time Complexity = O(n^2)
        Space Complexity = O(n^2)
    */

private:
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        return i >= 0 and i < grid.size() and j >= 0 and j < grid.size() and grid[i][j] == 0;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0])
            return -1;

        int res;

        queue<pair<int, int>> q1;
        q1.push({0, 0});
        grid[0][0] = 2;

        int n = grid.size();

        vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}};

        while (!q1.empty())
        {
            int size = q1.size();
            res++;

            while (size--)
            {
                int i = q1.front().first;
                int j = q1.front().second;
                q1.pop();

                if (i == n - 1 and j == n - 1)
                    return res;

                for (auto dir : dirc)
                {
                    int newX = i + dir.first;
                    int newY = j + dir.second;

                    if (isValid(newX, newY, grid))
                    {
                        grid[newX][newY] = 2;
                        q1.push({newX, newY});
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