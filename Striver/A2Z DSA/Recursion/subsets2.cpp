#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(2^n * n)
    Space Complexity : O(2^n * k) + O(n) - Auxiliary Space Complexity
*/

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> temp;

    void helper(int idx, vector<int> &nums)
    {
        res.push_back(temp);

        for (int i = idx; i < nums.size(); i++)
        {
            // repeating vaalo ko ignore karna hai jisse ki voh aage jake subsets na
            // banaye aur duplicates na bane unse
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            helper(i + 1, nums);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        helper(0, nums);
        return res;
    }
};