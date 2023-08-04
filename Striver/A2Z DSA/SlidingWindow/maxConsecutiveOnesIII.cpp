#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
    int longestOnes(vector<int> &nums, int k)
    {
        int start = 0, end = 0, res = 0;
        int ones = 0;

        while (end < nums.size())
        {
            if (nums[end])
            {
                ones++;
            }

            // length-ones<=k, then we can flip the remaining zeroes
            while ((end - start + 1) - ones > k)
            {
                if (nums[start])
                    ones--;
                start++;
            }

            res = max(res, end - start + 1);
            end++;
        }

        return res;
    }
};

int main()
{

    return 0;
}