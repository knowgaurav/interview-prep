#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
    long long countGood(vector<int> &nums, int k)
    {
        long long res = 0, start = 0, end = 0;
        int pairCount = 0, n = nums.size();
        unordered_map<int, int> m1;

        while (end < nums.size())
        {
            pairCount += m1[nums[end]];
            m1[nums[end]]++;

            // When condition is satisfied, we try to shrink the window reach its limit
            while (start < end && pairCount >= k)
            {
                res += n - end;
                m1[nums[start]]--;
                pairCount -= m1[nums[start]];
                start++;
            }

            end++;
        }

        return res;
    }
};

int main()
{

    return 0;
}