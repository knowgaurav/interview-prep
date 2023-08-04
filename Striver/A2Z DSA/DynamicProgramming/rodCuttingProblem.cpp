#include "bits/stdc++.h"
using namespace std;

int helper(int idx, int rodLength, vector<int> &price, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return dp[idx][rodLength] = rodLength * price[0];
    }

    if (dp[idx][rodLength] != -1)
    {
        return dp[idx][rodLength];
    }

    int notTake = helper(idx - 1, rodLength, price, dp);
    int cutLength = idx + 1;
    int take = INT_MIN;
    if (cutLength <= rodLength)
    {
        take = price[idx] + helper(idx, rodLength - cutLength, price, dp);
    }

    return dp[idx][rodLength] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return helper(n - 1, n, price, dp);
}

/*
    Tabulation - Space Optimised:
    Time Complexity : O(n*n)
    Space Complecity : O(n*n)
*/

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    for (int rodLength = 0; rodLength <= n; rodLength++)
    {
        dp[0][rodLength] = rodLength * price[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int rodLength = 0; rodLength <= n; rodLength++)
        {
            int notTake = dp[idx - 1][rodLength];
            int take = INT_MIN;
            int cutLength = idx + 1;

            if (cutLength <= rodLength)
            {
                take = price[idx] + dp[idx][rodLength - cutLength];
            }

            dp[idx][rodLength] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> prev(n + 1, -1);

    for (int rodLength = 0; rodLength <= n; rodLength++)
    {
        prev[rodLength] = rodLength * price[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(n + 1, -1);

        for (int rodLength = 0; rodLength <= n; rodLength++)
        {
            int notTake = prev[rodLength];
            int take = INT_MIN;
            int cutLength = idx + 1;

            if (cutLength <= rodLength)
            {
                take = price[idx] + curr[rodLength - cutLength];
            }

            curr[rodLength] = max(take, notTake);
        }

        prev = curr;
    }

    return prev[n];
}

int main()
{

    return 0;
}