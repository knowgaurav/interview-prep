#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int res = 0, start = 0, end = 0, combinedNumber = 0;

        while (end < nums.size())
        {
            while ((combinedNumber & nums[end]) > 0)
            {
                combinedNumber ^= nums[start];
                start++;
            }

            combinedNumber |= nums[end];
            res = max(res, end - start + 1);
            end++;
        }

        return res;
    }
};

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int res = 1;
        int start = 0, end = 0;
        int bMap[31] = {0}; // Binary Map

        while (end < nums.size())
        {
            bool flag = false;

            // Storing the binary representation of the current number
            for (int i = 0; i < 31; i++)
            {
                if (nums[end] & (1 << i))
                {
                    bMap[i]++;

                    if (bMap[i] > 1)
                    {
                        flag = true;
                    }
                }
            }

            // Check if any bit is repeating
            while (flag)
            {
                int num = nums[start];

                for (int i = 0; i < 31; i++)
                {
                    if (num & (1 << i))
                    {
                        bMap[i]--;
                    }
                }

                bool f = false;
                for (int i = 0; i < 31; i++)
                {
                    if (bMap[i] > 1)
                    {
                        f = true;
                    }
                }

                start++;

                if (!f)
                {
                    flag = false;
                }
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