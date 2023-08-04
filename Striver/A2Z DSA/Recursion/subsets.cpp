#include "bits/stdc++.h"
using namespace std;

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
            temp.push_back(nums[i]);
            helper(i + 1, nums);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        helper(0, nums);
        return res;
    }
};