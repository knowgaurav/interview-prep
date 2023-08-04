#include "bits/stdc++.h"
using namespace std;

int helper(int idx, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (sum == 0 and num[0] == 0)
            return 2;
        if (sum == 0 || sum == num[0])
            return 1;
        return 0;
    }

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int notPick = helper(idx - 1, sum, num, dp);
    int pick = 0;
    if (num[idx] <= sum)
        pick = helper(idx - 1, sum - num[idx], num, dp);

    return dp[idx][sum] = pick + notPick;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

    return helper(n - 1, tar, num, dp);
}

int findWays2(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar + 1, 0);
    prev[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(tar + 1, 0);
        curr[0] = 1;

        for (int sum = 1; sum <= tar; sum++)
        {
            int notPick = prev[sum];
            int pick = 0;
            if (num[idx] <= sum)
                pick = prev[sum - num[idx]];

            curr[sum] = pick + notPick;
        }

        prev = curr;
    }

    return prev[tar];
}

int findWays3(vector<int> &num, int k)
{
    int n = num.size();

    vector<int> prev(k + 1, 0);

    prev[0] = 1;

    if (num[0] <= k)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> cur(k + 1, 0);
        cur[0] = 1;
        for (int target = 1; target <= k; target++)
        {

            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = notTaken + taken;
        }

        prev = cur;
    }

    return prev[k];
}

int main()
{
    vector<int> nums = {1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
    cout << findWays2(nums, 1) << endl;
    cout << findWays3(nums, 1) << endl;
    return 0;
}