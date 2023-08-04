#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    int helper(int i, int j, int arr[], vector<vector<long long>> &dp)
    {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long pickFirst = arr[i] + min(helper(i + 2, j, arr, dp), helper(i + 1, j - 1, arr, dp));
        long long pickLast = arr[j] + min(helper(i + 1, j - 1, arr, dp), helper(i, j - 2, arr, dp));

        return dp[i][j] = max(pickFirst, pickLast);
    }

public:
    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n, -1));

        return helper(0, n - 1, arr, dp);
    }
};

class Solution
{
public:
    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n, -1));

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = arr[i];
                }
                else if (gap == 1)
                {
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else
                {
                    long long pickFirst = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    long long pickLast = arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);

                    dp[i][j] = max(pickFirst, pickLast);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main()
{

    return 0;
}