#include "bits/stdc++.h"
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Write your code here
    // int n = a.size();
    // int maxLen = 0;

    // for(int i=0; i<n; i++){
    //     long long currSum = 0;
    //     for(int j=i; j<n; j++){
    //         currSum += a[j];

    //         if(currSum == k){
    //             maxLen = max(maxLen, j-i+1);
    //         }
    //     }
    // }

    // sum, idx
    unordered_map<int, int> m1;
    int currSum = 0;
    int maxLen = 0;

    for (int i = 0; i < a.size(); i++)
    {
        currSum += a[i];

        if (currSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int diff = currSum - k;
        if (m1.find(diff) != m1.end())
        {
            maxLen = max(maxLen, i - m1[diff]);
        }

        if (m1.find(currSum) == m1.end())
            m1[currSum] = i;
    }

    return maxLen;
}

// Using Two Pointers / Sliding Window

/*
    Time Complexity = O(2N)
    Space Complexity = O(1)
*/

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Write your code here
    int maxLen = 0;
    long long currSum = a[0];
    int left = 0, right = 0, n = a.size();

    while (right < n)
    {
        while (left <= right && currSum > k)
        {
            currSum -= a[left];
            left++;
        }

        if (currSum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            currSum += a[right];
    }

    return maxLen;
}