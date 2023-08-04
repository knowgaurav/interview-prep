#include "bits/stdc++.h"
using namespace std;

/*
    Memoization:
    Time Complexity : O(N*2*3)
    Space Complexity : O(N*2*3)
*/

int helper(int idx, int buyFlag, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (limit == 0)
        return 0;
    if (idx == prices.size())
        return 0;

    if (dp[idx][buyFlag][limit] != -1)
        return dp[idx][buyFlag][limit];

    int profit = 0;

    if (buyFlag)
    {
        int buyKaro = -prices[idx] + helper(idx + 1, 0, limit, prices, dp);
        int ignoreKaro = 0 + helper(idx + 1, 1, limit, prices, dp);
        profit = max(buyKaro, ignoreKaro);
    }
    else
    {
        int sellKaro = prices[idx] + helper(idx + 1, 1, limit - 1, prices, dp);
        int ignoreKaro = 0 + helper(idx + 1, 0, limit, prices, dp);
        profit = max(sellKaro, ignoreKaro);
    }

    return dp[idx][buyFlag][limit] = profit;
}

int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return helper(0, 1, 2, prices, dp);
}

/*
    Tabulation:
    Time Complexity : O(N*2*3)
    Space Complexity : O(N*2*3)
*/

int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buyFlag = 0; buyFlag <= 1; buyFlag++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;

                if (buyFlag)
                {
                    int buyKaro = -prices[idx] + dp[idx + 1][0][limit];
                    int ignoreKaro = 0 + dp[idx + 1][1][limit];
                    profit = max(buyKaro, ignoreKaro);
                }
                else
                {
                    int sellKaro = prices[idx] + dp[idx + 1][1][limit - 1];
                    int ignoreKaro = 0 + dp[idx + 1][0][limit];
                    profit = max(sellKaro, ignoreKaro);
                }

                dp[idx][buyFlag][limit] = profit;
            }
        }
    }

    return dp[0][1][2];
}

int main()
{

    return 0;
}