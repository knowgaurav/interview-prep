#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N^2)
    Space Complexity : O(N) + O(N)
*/

int helper(int i, vector<int> &nums, int k, vector<int> &dp)
{
    if (i == nums.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int n = nums.size(), len = 0, maxEle = INT_MIN, res = INT_MIN;
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxEle = max(maxEle, nums[j]);
        int cost = (maxEle * len) + helper(j + 1, nums, k, dp);

        res = max(res, cost);
    }

    return dp[i] = res;
}

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    vector<int> dp(num.size() + 1, -1);
    return helper(0, num, k, dp);
}

/*
    Time Complexity : O(N^2)
    Space Complexity : O(N)
*/

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    vector<int> dp(num.size() + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0, maxEle = INT_MIN, res = INT_MIN;

        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxEle = max(maxEle, num[j]);
            int cost = (maxEle * len) + dp[j + 1];

            res = max(res, cost);
        }

        dp[i] = res;
    }

    return dp[0];
}

int main()
{

    return 0;
}