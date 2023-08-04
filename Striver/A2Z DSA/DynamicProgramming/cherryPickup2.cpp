#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Memoization:
        Time Complexity : O(m*n*n)
        Space Complexity : O(m*n*n)
    */

private:
    int m, n;
    int dirc[3] = {-1, 0, +1};
    int dp[71][71][71];

    int helper(int r, int c1, int c2, vector<vector<int>> &grid)
    {
        if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
            return -1e9;
        if (r == m)
            return 0;
        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int maxRes = 0;

        for (int k1 = 0; k1 < 3; k1++)
        {
            for (int k2 = 0; k2 < 3; k2++)
            {
                maxRes = max(maxRes, helper(r + 1, c1 - dirc[k1], c2 - dirc[k2], grid));
            }
        }

        maxRes += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = maxRes;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return helper(0, 0, n - 1, grid);
    }
};

class Solution
{

    /*
        Tabulation:
        Time Complexity : O(m*n*n)
        Space Complexity : O(m*n)
    */

public:
    int dirc[3] = {-1, 0, +1};

    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prev(n, vector<int>(n, 0));

        for (int c1 = 0; c1 < n; c1++)
        {
            for (int c2 = 0; c2 < n; c2++)
            {
                prev[c1][c2] = (c1 == c2) ? grid[m - 1][c1] : grid[m - 1][c1] + grid[m - 1][c2];
            }
        }

        for (int r = m - 2; r >= 0; r--)
        {
            vector<vector<int>> curr(n, vector<int>(n, 0));

            for (int c1 = 0; c1 < n; c1++)
            {
                for (int c2 = 0; c2 < n; c2++)
                {

                    int maxRes = 0;

                    for (int k1 = 0; k1 < 3; k1++)
                    {
                        for (int k2 = 0; k2 < 3; k2++)
                        {
                            if (c1 + dirc[k1] >= 0 && c1 + dirc[k1] < n && c2 + dirc[k2] >= 0 && c2 + dirc[k2] < n)
                            {
                                maxRes = max(maxRes, prev[c1 + dirc[k1]][c2 + dirc[k2]]);
                            }
                        }
                    }

                    curr[c1][c2] += maxRes;
                    curr[c1][c2] += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
                }
            }

            prev = curr;
        }

        return prev[0][n - 1];
    }
};

int main()
{

    return 0;
}