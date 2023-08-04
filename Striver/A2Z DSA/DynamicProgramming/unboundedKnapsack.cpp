#include "bits/stdc++.h"
using namespace std;

int helper(int idx, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return dp[idx][W] = (W / weight[0]) * profit[0];
    }

    if (dp[idx][W] != -1)
        return dp[idx][W];

    int notTake = 0 + helper(idx - 1, W, profit, weight, dp);
    int take = INT_MIN;
    if (weight[idx] <= W)
    {
        take = profit[idx] + helper(idx, W - weight[idx], profit, weight, dp);
    }

    return dp[idx][W] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    return helper(n - 1, w, profit, weight, dp);
}

/*
    Tabulation:
    Time Complexity : O(n*targetWeight)
    Space Complecity : O(n*targetWeight)
*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int wt = 0; wt <= w; wt++)
    {
        dp[0][wt] = (wt / weight[0]) * profit[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int wt = 1; wt <= w; wt++)
        {
            int notTake = dp[idx - 1][wt];
            int take = INT_MIN;
            if (weight[idx] <= wt)
            {
                take = profit[idx] + dp[idx][wt - weight[idx]];
            }

            dp[idx][wt] = max(take, notTake);
        }
    }

    return dp[n - 1][w];
}

/*
    Tabulation - Space Optimised:
    Time Complexity : O(n*targetWeight)
    Space Complecity : O(targetWeight)
*/

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> prev(w + 1, 0);

    for (int wt = 0; wt <= w; wt++)
    {
        prev[wt] = (wt / weight[0]) * profit[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int wt = 1; wt <= w; wt++)
        {
            int notTake = 0 + prev[wt];
            int take = INT_MIN;
            if (weight[idx] <= wt)
            {
                take = profit[idx] + prev[wt - weight[idx]];
            }

            prev[wt] = max(take, notTake);
        }
    }

    return prev[w];
}

int main()
{

    return 0;
}