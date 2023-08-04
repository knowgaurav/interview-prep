#include "bits/stdc++.h"
using namespace std;

/*
    Memoization:
    Time Complexity : O(N*target)
    Space Compleixty : O(N*target) + O(target)
*/

int helper(int idx, vector<int> &num, int target, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target % num[idx] == 0)
        {
            return dp[idx][target] = target / num[idx];
        }
        return 1e9;
    }

    if (dp[idx][target] != -1)
        return dp[idx][target];

    int notPick = 0 + helper(idx - 1, num, target, dp);
    int pick = INT_MAX;
    if (num[idx] <= target)
    {
        pick = 1 + helper(idx, num, target - num[idx], dp);
    }

    return dp[idx][target] = min(notPick, pick);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    int res = helper(n - 1, num, x, dp);

    return res == 1e9 ? -1 : res;
}

/*
    Tabulation:
    Time Complexity : O(N*target)
    Space Compleixty : O(N*target)
*/

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int target = 0; target <= x; target++)
    {
        if (target % num[0] == 0)
        {
            dp[0][target] = target / num[0];
        }
        else
        {
            dp[0][target] = 1e9;
        }
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= x; target++)
        {
            int notPick = dp[idx - 1][target];
            int pick = INT_MAX;

            if (num[idx] <= target)
            {
                pick = 1 + dp[idx][target - num[idx]];
            }
            dp[idx][target] = min(notPick, pick);
        }
    }

    return dp[n - 1][x] == 1e9 ? -1 : dp[n - 1][x];
}

/*
    Tabulation - Space Optimised:
    Time Complexity : O(N*target)
    Space Compleixty : O(target)
*/

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(x + 1, 0);

    for (int target = 0; target <= x; target++)
    {
        if (target % num[0] == 0)
        {
            prev[target] = target / num[0];
        }
        else
        {
            prev[target] = 1e9;
        }
    }

    for (int idx = 1; idx < n; idx++)
    {
        vector<int> curr(x + 1, 0);

        for (int target = 1; target <= x; target++)
        {
            int notPick = prev[target];
            int pick = INT_MAX;

            if (num[idx] <= target)
            {
                pick = 1 + curr[target - num[idx]];
            }
            curr[target] = min(notPick, pick);
        }

        prev = curr;
    }

    return prev[x] == 1e9 ? -1 : prev[x];
}

int main()
{

    return 0;
}