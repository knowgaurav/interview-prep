#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(n) + O(n)
        Space Complexity : O(n)
    */

private:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;

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

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> withoutFirst, withoutLast;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                withoutFirst.push_back(nums[i]);
            }

            if (i != nums.size() - 1)
            {
                withoutLast.push_back(nums[i]);
            }
        }

        return max(solve(withoutFirst), solve(withoutLast));
    }
};

int main()
{

    return 0;
}