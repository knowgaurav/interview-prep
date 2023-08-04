#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(2^n)
    Space Complexity : O(n)
*/

class Solution
{
private:
    void helper(int idx, int currSum, int total, vector<int> &temp, vector<int> &nums, vector<vector<int>> &res)
    {
        if (idx >= nums.size())
        {
            if (currSum == total)
            {
                res.push_back(temp);
            }
            return;
        }

        if (currSum == total)
        {
            res.push_back(temp);
            return;
        }

        // Include the current element
        if (currSum + nums[idx] <= total)
        {
            currSum += nums[idx];
            temp.push_back(nums[idx]);
            helper(idx, currSum, total, temp, nums, res);
            temp.pop_back();
            currSum -= nums[idx];
        }

        // Exclude the current element
        helper(idx + 1, currSum, total, temp, nums, res);
    }

public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int total)
    {
        // Your code here
        vector<vector<int>> res;
        vector<int> temp;
        int currSum = 0;
        sort(begin(A), end(A));
        A.erase(unique(A.begin(), A.end()), A.end());

        helper(0, currSum, total, temp, A, res);

        return res;
    }
};

class Solution
{
private:
    vector<vector<int>> res;

    void helper(int idx, int target, vector<int> &nums, vector<int> &temp)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }

        if (idx >= nums.size())
            return; // kuch nahi bacha vapis chale jao

        // idx vale element ko baar baar lete rahe aut jab vapis backtrack karo toh idx ko badha do
        // isse ye fayeda hoga ki purane element comvbination mein nahi aayenge
        // matlab ki agar target 3 bana rahe hai toh (1,1,1) ek sol hoga aur firr (1, 2) dusra hoga
        // agar same idx shuruwat 0 se pass kardete toh (2, 1) bhi sol ban jata jo hame nahi chahiye ans mein
        while (idx < nums.size() && nums[idx] <= target)
        {
            // element ko lelo
            temp.push_back(nums[idx]);
            helper(idx, target - nums[idx], nums, temp);

            // vapis aa gaye toh idx++ aur purane element ko hta do
            idx++;
            temp.pop_back();
        }
    }

public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        set<int> s1(begin(A), end(A));
        A.assign(begin(s1), end(s1));
        vector<int> temp;

        // idx, target, nums, temp
        helper(0, B, A, temp);

        return res;
    }
};