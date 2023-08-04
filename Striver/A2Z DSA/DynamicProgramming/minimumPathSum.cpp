#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Memoization:
        Time Complexity : O(m*n)
        Space Complexity : O(m-1, n-1) + O(m*n)
    */

private:
    int m, n;

    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return INT_MAX;
        if (i == 0 && j == 0)
            return dp[i][j] = grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        // Go Up
        int up = helper(i - 1, j, grid, dp);

        // Go Left
        int left = helper(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left) + grid[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        helper(m - 1, n - 1, grid, dp);

        return dp[m - 1][n - 1];
    }
};

class Solution
{

    /*
        Tabulation:
        Time Complexity : O(m*n)
        Space Complexity : O(m*n)
    */

private:
    int m, n;

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = min(up, left) + grid[i][j];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{

    return 0;
}