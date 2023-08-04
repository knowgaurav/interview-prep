#include "bits/stdc++.h"
using namespace std;

// Memoization
int helper(int idx, int maxWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return dp[0][maxWeight] = value[0];
        }

        return dp[0][maxWeight] = 0;
    }

    if (dp[idx][maxWeight] != -1)
        return dp[idx][maxWeight];

    int notPick = helper(idx - 1, maxWeight, weight, value, dp);
    int pick = INT_MIN;
    if (weight[idx] <= maxWeight)
    {
        pick = value[idx] + helper(idx - 1, maxWeight - weight[idx], weight, value, dp);
    }

    return dp[idx][maxWeight] = max(notPick, pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    helper(n - 1, maxWeight, weight, value, dp);

    return dp[n - 1][maxWeight];
}

// Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int currWt = 1; currWt <= maxWeight; currWt++)
        {
            int notPick = dp[idx - 1][currWt];
            int pick = INT_MIN;
            if (weight[idx] <= currWt)
            {
                pick = value[idx] + dp[idx - 1][currWt - weight[idx]];
            }

            dp[idx][currWt] = max(pick, notPick);
        }
    }

    return dp[n - 1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<int> prev(maxWeight + 1, 0);

    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(maxWeight + 1, 0);

        for (int currWt = 0; currWt <= maxWeight; currWt++)
        {
            int notPick = prev[currWt];
            int pick = INT_MIN;
            if (weight[idx] <= currWt)
            {
                pick = value[idx] + prev[currWt - weight[idx]];
            }

            curr[currWt] = max(pick, notPick);
        }

        prev = curr;
    }

    return prev[maxWeight];
}

// Space Optimised Tabulation
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int weight[], int val[], int n)
    {
        // Your code here
        vector<int> prev(W + 1, 0);

        // Base Case
        for (int wt = weight[0]; wt <= W; wt++)
        {
            prev[wt] = val[0];
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int wt = W; wt >= 0; wt--)
            {
                int notPick = prev[wt];
                int pick = INT_MIN;
                if (weight[idx] <= wt)
                {
                    pick = val[idx] + prev[wt - weight[idx]];
                }

                prev[wt] = max(notPick, pick);
            }
        }

        return prev[W];
    }
};

int main()
{

    return 0;
}