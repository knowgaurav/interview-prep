/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        if (n == 1)
            return dp[0];

        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int inc = nums[i] + dp[i - 2];
            int exc = dp[i - 1];
            dp[i] = max(inc, exc);
        }

        return dp[n - 1];
    }
};
// @lc code=end
