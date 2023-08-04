#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

private:
    int atmostKTimes(vector<int> &nums, int k)
    {
        int res = 0, start = 0, end = 0, oddCount = 0;

        while (end < nums.size())
        {
            if (nums[end] % 2)
                oddCount++;

            while (oddCount > k)
            {
                if (nums[start] % 2)
                    oddCount--;
                start++;
            }

            res += (end - start + 1);
            end++;
        }

        return res;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atmostKTimes(nums, k) - atmostKTimes(nums, k - 1);
    }
};

int main()
{

    return 0;
}