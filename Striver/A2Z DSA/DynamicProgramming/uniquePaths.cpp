#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(2^(m*n))
        Space Complexity : O(Path length) + O(m*n)
    */

private:
    int m, n, res = 0;

    void helper(int i, int j, vector<vector<bool>> visited)
    {
        if (i == m - 1 || j == n - 1)
        {
            res++;
            return;
        }

        // Down call
        visited[i][j] = true;
        helper(i + 1, j, visited);
        visited[i][j] = false;

        // Right call
        visited[i][j] = true;
        helper(i, j + 1, visited);
        visited[i][j] = false;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        this->m = m;
        this->n = n;

        helper(0, 0, visited);

        return res;
    }
};

class Solution
{

    /*
        Memoization :
        Time Complexity : O(m*n)
        Space Complexity : O((n-1)+(m-1)) + O(m*n)
    */

private:
    int m, n;

    int helper(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return 0;
        if (i == 0 || j == 0)
            return dp[i][j] = 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        visited[i][j] = true;
        int paths = helper(i - 1, j, visited, dp) + helper(i, j - 1, visited, dp);
        visited[i][j] = false;

        return dp[i][j] = paths;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dp(m, vector<int>(n, -1));

        this->m = m;
        this->n = n;

        helper(m - 1, n - 1, visited, dp);

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
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{

    return 0;
}