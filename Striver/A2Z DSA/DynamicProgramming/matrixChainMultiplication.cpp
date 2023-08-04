#include "bits/stdc++.h"
using namespace std;

int helper(int i, int j, vector<int> arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int res = 1e9;

    for (int k = i; k < j; k++)
    {
        int cost = arr[i - 1] * arr[k] * arr[j] + helper(i, k, arr, dp) + helper(k + 1, j, arr, dp);
        res = min(cost, res);
    }

    return dp[i][j] = res;
}

/*
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int res = 1e9;

            for (int k = i; k < j; k++)
            {
                int cost = arr[i - 1] * arr[k] * arr[j] +
                           dp[i][k] +
                           dp[k + 1][j];
                res = min(cost, res);
            }

            dp[i][j] = res;
        }
    }

    return dp[1][N - 1];
}

int main()
{

    return 0;
}