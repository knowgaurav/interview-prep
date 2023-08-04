#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(n)
        Space Complexity : O(n) + O(n)
    */

private:
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == 0)
            return nums[0];
        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + solve(i - 2, nums, dp);
        int notPick = 0 + solve(i - 1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);

        solve(n - 1, nums, dp);
        return dp[n - 1];
    }
};

class Solution
{

    /*
        Time Complexity : O(n)
        Space Complexity : O(n)
    */

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }

            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};

class Solution
{

    /*
        Time Complexity : O(n)
        Space Complexity : O(1)
    */

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev2 = 0, prev = nums[0];

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i] + prev2;
            int notPick = 0 + prev;

            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main()
{

    return 0;
}