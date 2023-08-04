#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    vector<vector<int>> res;

    void helper(int idx, int target, int k, vector<int> &temp, vector<int> &nums)
    {
        if (target == 0 && temp.size() == k)
        {
            res.push_back(temp);
            return;
        }

        if (idx >= nums.size())
            return;
        if (temp.size() > k)
            return;

        for (int i = idx; i < nums.size(); i++)
        {
            if (nums[i] <= target)
            {
                temp.push_back(nums[i]);
                helper(i + 1, target - nums[i], k, temp, nums);

                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> nums;
        for (int i = 1; i <= 9; i++)
            nums.push_back(i);
        vector<int> temp;

        // idx, currSum, target, k, temp
        helper(0, n, k, temp, nums);
        return res;
    }
};