#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    int n;
    vector<vector<int>> res;
    vector<int> temp;

    void helper(vector<int> &nums, vector<bool> &taken)
    {
        if (temp.size() == n)
        {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            // Don't taken the element if previous similar element is not taken
            if (i > 0 and nums[i] == nums[i - 1] and !taken[i - 1])
                continue;

            if (!taken[i])
            {
                temp.push_back(nums[i]);
                taken[i] = true;
                helper(nums, taken);
                taken[i] = false;
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        vector<bool> taken(n, false);
        sort(begin(nums), end(nums));
        helper(nums, taken);
        return res;
    }
};

class Solution
{
private:
    vector<vector<int>> res;

    void helper(int idx, vector<int> &nums)
    {
        if (idx >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        // To take unique elements only on every call for further recursion
        unordered_set<int> s1;

        for (int i = idx; i < nums.size(); i++)
        {
            if (s1.find(nums[i]) != s1.end())
                continue;

            s1.insert(nums[i]);
            swap(nums[i], nums[idx]);
            helper(idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        helper(0, nums);
        return res;
    }
};

int main()
{

    return 0;
}