#include "bits/stdc++.h"
using namespace std;

/*
    Memoization:
    Time Complexity : O(n*n)
    Space Complexity : O(n) + O(n*n)
*/

int helper(int row, int col, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (row == n - 1)
    {
        return triangle[row][col];
    }

    if (dp[row][col] != -1)
        return dp[row][col];

    int down, downRight;
    down = downRight = INT_MAX;

    down = helper(row + 1, col, triangle, n, dp);
    downRight = helper(row + 1, col + 1, triangle, n, dp);

    return dp[row][col] = triangle[row][col] + min(down, downRight);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(0, 0, triangle, n, dp);
}

class Solution
{

    /*
        Tabulation:
        Time Complexity : O(n*n)
        Space Complexity : O(n*n)
    */

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int up, upLeft;
                up = upLeft = INT_MAX;

                if (j < i)
                    up = dp[i - 1][j];
                if (j > 0)
                    upLeft = dp[i - 1][j - 1];

                dp[i][j] = min(up, upLeft) + triangle[i][j];
            }
        }

        int res = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            res = min(res, dp[n - 1][i]);
        }

        return res;
    }
};

int main()
{

    return 0;
}