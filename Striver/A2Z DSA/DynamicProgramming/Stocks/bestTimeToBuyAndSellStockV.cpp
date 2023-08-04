#include "bits/stdc++.h"
using namespace std;

int helper(int idx, int buyFlag, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx >= prices.size())
        return 0;

    if (dp[idx][buyFlag] != -1)
        return dp[idx][buyFlag];

    int profit = 0;

    if (buyFlag)
    {
        int buyKaro = -prices[idx] + helper(idx + 1, 0, prices, dp);
        int ignoreKaro = 0 + helper(idx + 1, 1, prices, dp);
        profit = max(buyKaro, ignoreKaro);
    }
    else
    {
        int sellKaro = prices[idx] + helper(idx + 2, 1, prices, dp);
        int ignoreKaro = 0 + helper(idx + 1, 0, prices, dp);
        profit = max(sellKaro, ignoreKaro);
    }

    return dp[idx][buyFlag] = profit;
}

int stockProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    return helper(0, 1, prices, dp);
}

int stockProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buyFlag = 0; buyFlag < 2; buyFlag++)
        {
            int profit = 0;

            if (buyFlag)
            {
                int buyKaro = -prices[idx] + dp[idx + 1][0];
                int ignoreKaro = 0 + dp[idx + 1][1];
                profit = max(buyKaro, ignoreKaro);
            }
            else
            {
                int sellKaro = prices[idx] + dp[idx + 2][1];
                int ignoreKaro = 0 + dp[idx + 1][0];
                profit = max(sellKaro, ignoreKaro);
            }

            dp[idx][buyFlag] = profit;
        }
    }

    return dp[0][1];
}

int main()
{

    return 0;
}