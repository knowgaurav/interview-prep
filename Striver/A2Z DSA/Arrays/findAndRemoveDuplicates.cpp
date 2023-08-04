#include "bits/stdc++.h"
using namespace std;

// Brute Force
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> s1(begin(nums), end(nums));
        set<int>::iterator itr;
        int i = 0;

        for (itr = s1.begin(); itr != s1.end(); itr++)
        {
            nums[i] = *itr;
            i++;
        }

        return s1.size();
    }
};

// Optimal Solution
class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        // code here
        int correctIdx = 0;

        for (int unique = 1; unique < n; unique++)
        {
            if (a[unique] != a[correctIdx])
            {
                a[++correctIdx] = a[unique];
            }
        }

        return correctIdx + 1;
    }
};