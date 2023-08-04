#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        int fact = 1;
        vector<int> nums;

        for (int i = 1; i < n; i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);

        k -= 1;

        string res = "";

        while (true)
        {
            res += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
                break;

            k = k % fact;
            fact = fact / nums.size();
        }

        return res;
    }
};