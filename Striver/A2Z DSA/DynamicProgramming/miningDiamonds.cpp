#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/

int helper(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int res = INT_MIN;
    for (int idx = i; idx <= j; idx++)
    {
        int coins = a[i - 1] * a[idx] * a[j + 1] + helper(i, idx - 1, a, dp) + helper(idx + 1, j, a, dp);
        res = max(res, coins);
    }

    return dp[i][j] = res;
}

int maxCoins(vector<int> &a)
{
    // Write your code here.
    int N = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    return helper(1, N, a, dp);
}

int maxCoins(vector<int> &a)
{
    // Write your code here.
    int N = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);

    vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

    for (int i = N; i >= 1; i--)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i > j)
                continue;

            int res = INT_MIN;
            for (int idx = i; idx <= j; idx++)
            {
                int coins = a[i - 1] * a[idx] * a[j + 1] + dp[i][idx - 1] + dp[idx + 1][j];
                res = max(res, coins);
            }

            dp[i][j] = res;
        }
    }

    return dp[1][N];
}

int main()
{

    return 0;
}