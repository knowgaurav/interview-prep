#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        leftMax[1] = nums[0];
        rightMax[n - 2] = nums[n - 1];

        for (int i = 2; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }

        for (int j = n - 3; j >= 0; j--)
        {
            rightMax[j] = max(rightMax[j + 1], nums[j + 1]);
        }

        long long res = 0;

        for (int i = 1; i < n - 1; i++)
        {
            res = max(res, (long long)(leftMax[i] - nums[i]) * rightMax[i]);
        }

        return res;
    }
};

int main()
{

    return 0;
}