#include "bits/stdc++.h"
using namespace std;

/*
    Memoization:
    Time Complexity : O(m*n*n)
    Space Complexity : O(m) + O(m*n)
*/

int helper(int row, int col, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
{
    if (row == matrix.size() - 1)
    {
        return matrix[row][col];
    }

    if (dp[row][col] != -1)
        return dp[row][col];

    int down, downLeft, downRight;
    down = downLeft = downRight = INT_MIN;

    down = helper(row + 1, col, matrix, n, dp);
    if (col > 0)
        downLeft = helper(row + 1, col - 1, matrix, n, dp);
    if (col < n - 1)
        downRight = helper(row + 1, col + 1, matrix, n, dp);

    return dp[row][col] = matrix[row][col] + max(down, max(downLeft, downRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix[0].size(), res = INT_MIN;
    vector<vector<int>> dp(matrix.size(), vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        int currPath = helper(0, i, matrix, n, dp);
        res = max(res, currPath);
    }

    return res;
}

/*
    Tabulation:
    Time Complexity : O(2m) + O(m*n)
    Space Complexity : O(m*n)
*/

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up, upLeft, upRight;
            up = upLeft = upRight = INT_MIN;

            up = dp[i - 1][j];
            if (j > 0)
                upLeft = dp[i - 1][j - 1];
            if (j < n - 1)
                upRight = dp[i - 1][j + 1];

            dp[i][j] = max(up, max(upLeft, upRight)) + matrix[i][j];
        }
    }

    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[m - 1][i]);
    }

    return res;
}

int main()
{

    return 0;
}