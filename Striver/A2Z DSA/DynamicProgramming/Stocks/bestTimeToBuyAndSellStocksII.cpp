#include "bits/stdc++.h"
using namespace std;

long helper(int idx, int buyFlag, long *values, int n, vector<vector<long>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][buyFlag] != -1)
        return dp[idx][buyFlag];

    long profit = 0;

    if (buyFlag)
    {
        profit = max(-values[idx] + helper(idx + 1, 0, values, n, dp),
                     0 + helper(idx + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[idx] + helper(idx + 1, 1, values, n, dp),
                     0 + helper(idx + 1, 0, values, n, dp));
    }

    return dp[idx][buyFlag] = profit;
}

long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(2, -1));

    return helper(0, 1, values, n, dp);
}

long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    dp[n][0] = dp[n][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buyFlag = 0; buyFlag < 2; buyFlag++)
        {
            long profit = 0;

            if (buyFlag)
            {
                long buyKaro = -values[idx] + dp[idx + 1][0];
                long ignoreKaro = 0 + dp[idx + 1][1];
                profit = max(buyKaro, ignoreKaro);
            }
            else
            {
                long sellKaro = values[idx] + dp[idx + 1][1];
                long ignoreKaro = 0 + dp[idx + 1][0];
                profit = max(sellKaro, ignoreKaro);
            }

            dp[idx][buyFlag] = profit;
        }
    }

    return dp[0][1];
}

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<int> next(n + 1, 0);
    next[0] = next[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(n + 1, 0);

        for (int buyFlag = 0; buyFlag < 2; buyFlag++)
        {
            long profit = 0;

            if (buyFlag)
            {
                long buyKaro = -values[idx] + next[0];
                long ignoreKaro = 0 + next[1];
                profit = max(buyKaro, ignoreKaro);
            }
            else
            {
                long sellKaro = values[idx] + next[1];
                long ignoreKaro = 0 + next[0];
                profit = max(sellKaro, ignoreKaro);
            }

            curr[buyFlag] = profit;
        }

        next = curr;
    }

    return next[1];
}

int main()
{

    return 0;
}