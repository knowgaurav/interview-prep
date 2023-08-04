#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res = 0, start = 0, end = 0;

        while (end < nums.size())
        {
            if (nums[end] != 0)
            {
                end++;
                start = end;
            }
            else
            {
                res += end - start + 1;
                end++;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}