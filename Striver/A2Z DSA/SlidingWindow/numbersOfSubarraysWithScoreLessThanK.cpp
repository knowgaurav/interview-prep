#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long res = 0, currSum = 0;
        int start = 0, end = 0;

        while (end < nums.size())
        {
            currSum += nums[end];

            while (currSum * (end - start + 1) >= k)
            {
                currSum -= nums[start];
                start++;
            }

            res += (end - start + 1);
            end++;
        }

        return res;
    }
};

int main()
{

    return 0;
}