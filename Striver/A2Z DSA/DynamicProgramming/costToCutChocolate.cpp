#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N^3)
    Space Complexity : O(N^2)
*/

int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int res = INT_MAX;

    for (int idx = i; idx <= j; idx++)
    {
        res = min(res, cuts[j + 1] - cuts[i - 1] +
                           helper(i, idx - 1, cuts, dp) + helper(idx + 1, j, cuts, dp));
    }

    return dp[i][j] = res;
}

int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(begin(cuts), end(cuts));

    return helper(1, c, cuts, dp);
}

/*
    Time Complexity : O(N^3)
    Space Complexity : O(N^2)
*/

int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(begin(cuts), end(cuts));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;

            int res = INT_MAX;
            for (int idx = i; idx <= j; idx++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][idx - 1] + dp[idx + 1][j];
                res = min(res, cost);
            }

            dp[i][j] = res;
        }
    }

    return dp[1][c];
}

int main()
{

    return 0;
}