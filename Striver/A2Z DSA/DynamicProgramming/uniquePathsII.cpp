#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Memoization :
        Time Complexity : O(m*n)
        Space Complexity : O((n-1)+(m-1)) + O(m*n)
    */

private:
    int m, n;
    int mod = 2e9 + 7;

    int helper(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] == 2)
            return 0;

        if (obstacleGrid[i][j] == 1)
            return dp[i][j] = 0;

        if (i == 0 && j == 0)
            return dp[i][j] = 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        obstacleGrid[i][j] = 2;
        int up = helper(i - 1, j, obstacleGrid, dp);
        int left = helper(i, j - 1, obstacleGrid, dp);
        obstacleGrid[i][j] = 0;

        return dp[i][j] = (left + up) % mod;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        helper(m - 1, n - 1, obstacleGrid, dp);

        return dp[m - 1][n - 1];
    }
};

class Solution
{

    /*
        Tabulation :
        Time Complexity : O(m*n)
        Space Complexity : O(m*n)
    */

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
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