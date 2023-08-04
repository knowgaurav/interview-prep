#include "bits/stdc++.h"
using namespace std;

int helper(int idx, int opNo, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx == prices.size())
        return 0;
    if (opNo == 2 * k)
        return 0;

    if (dp[idx][opNo] != -1)
        return dp[idx][opNo];

    int profit = 0;

    if (opNo % 2 == 0)
    {
        int buyKaro = -prices[idx] + helper(idx + 1, opNo + 1, k, prices, dp);
        int ignoreKaro = 0 + helper(idx + 1, opNo, k, prices, dp);
        profit = max(buyKaro, ignoreKaro);
    }
    else
    {
        int sellKaro = prices[idx] + helper(idx + 1, opNo + 1, k, prices, dp);
        int ignoreKaro = 0 + helper(idx + 1, opNo, k, prices, dp);
        profit = max(sellKaro, ignoreKaro);
    }

    return dp[idx][opNo] = profit;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(2 * k, -1));

    return helper(0, 0, k, prices, dp);
}

int main()
{

    return 0;
}