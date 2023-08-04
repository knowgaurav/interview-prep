#include "bits/stdc++.h"
using namespace std;

long helper(int idx, int value, int *denominations, int n, vector<vector<long>> &dp)
{
    if (idx == 0)
    {
        return dp[idx][value] = (value % denominations[0] == 0);
    }

    if (dp[idx][value] != -1)
        return dp[idx][value];

    long notPick = helper(idx - 1, value, denominations, n, dp);
    long pick = 0;
    if (denominations[idx] <= value)
    {
        pick = helper(idx, value - denominations[idx], denominations, n, dp);
    }

    return dp[idx][value] = pick + notPick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));

    return helper(n - 1, value, denominations, n, dp);
}

int main()
{

    return 0;
}