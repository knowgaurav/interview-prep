#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
    int longestSubarray(vector<int> &nums)
    {
        int res = 0, zeroes = 0;
        int start = 0, end = 0;

        while (end < nums.size())
        {
            if (nums[end] == 0)
                zeroes++;

            while (zeroes > 1)
            {
                if (nums[start] == 0)
                    zeroes--;
                start++;
            }

            res = max(res, end - start + 1);
            end++;
        }

        return res - 1;
    }
};

int main()
{

    return 0;
}