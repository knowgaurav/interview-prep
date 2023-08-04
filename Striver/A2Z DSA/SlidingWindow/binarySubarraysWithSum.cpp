#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    int countNumberOfSubarrayWithGivenSum(vector<int> &nums, int goal)
    {
        int res = 0, start = 0, end = 0, currSum = 0;

        while (end < nums.size())
        {
            currSum += nums[end];

            while (currSum > goal)
            {
                currSum -= nums[start++];
            }

            res += (end - start + 1);
            end++;
        }

        return res;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        if (goal == 0)
            return countNumberOfSubarrayWithGivenSum(nums, goal);

        return countNumberOfSubarrayWithGivenSum(nums, goal) - countNumberOfSubarrayWithGivenSum(nums, goal - 1);
    }
};

int main()
{

    return 0;
}