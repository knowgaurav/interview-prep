#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(n*n!)
        Space Complexity : O(n) + O(n)
    */

private:
    vector<vector<int>> res;
    vector<int> temp;

    void helper(vector<int> &nums, vector<bool> &freq)
    {
        // agar temp ka size n ke barabar ho jata hai matlab permutation ready hai
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        // 0 - n-1 tak jao aur dekho agar voh lia nahi hai toh usse lelo aur next call mardo
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                freq[i] = true;
                temp.push_back(nums[i]);
                helper(nums, freq);
                temp.pop_back();
                freq[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> freq(n, false);
        helper(nums, freq);

        return res;
    }
};

// Optimal Solution
class Solution
{

    /*
        Time Complexity : O(n*n!)
        Space Complexity : O(n)
    */

private:
    vector<vector<int>> res;
    vector<int> temp;

    void helper(vector<int> &nums, vector<bool> &freq)
    {
        // agar temp ka size n ke barabar ho jata hai matlab permutation ready hai
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        // 0 - n-1 tak jao aur dekho agar voh lia nahi hai toh usse lelo aur next call mardo
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                freq[i] = true;
                temp.push_back(nums[i]);
                helper(nums, freq);
                temp.pop_back();
                freq[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> freq(n, false);
        helper(nums, freq);

        return res;
    }
};