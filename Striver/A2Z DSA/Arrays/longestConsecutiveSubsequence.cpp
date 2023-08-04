#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        int maxLen = 0;
        vector<bool> visited(1000001, false);

        for (int i = 0; i < N; i++)
        {
            int ele = arr[i];
            int count = 1;

            if (!visited[ele])
            {
                while (find(arr, arr + N, ele + 1) != arr + N)
                {
                    visited[ele] = true;
                    count++;
                    ele++;
                }
            }

            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        int maxCount = 1;
        int currCount = 0, currSequence = INT_MIN;

        sort(arr, arr + N);

        for (int i = 0; i < N; i++)
        {
            // current element can be part of the current subsequence
            if (arr[i] - 1 == currSequence)
            {
                currCount++;
                currSequence = arr[i];
            }
            // can not be part of the current subsequence so start a new subsequence
            // as 1 less is not there in the current sequence else it would have been counted in the
            // above if case
            else if (arr[i] != currSequence)
            {
                currCount = 1;
                currSequence = arr[i];
            }

            maxCount = max(maxCount, currCount);
        }

        return maxCount;
    }
};

// Optimal
int longestSuccessiveElements(vector<int> &a)
{
    // Write your code here.

    /*
        Time Complexity = O(N) + O(2N)
        Space Complexity = O(N)
    */

    unordered_set<int> s1;

    for (int &ele : a)
    {
        s1.insert(ele);
    }

    int maxSequence = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (s1.find(a[i] - 1) == s1.end())
        {
            int ele = a[i];
            int currLen = 1;
            while (s1.find(ele + 1) != s1.end())
            {
                currLen++;
                ele++;
            }

            maxSequence = max(maxSequence, currLen);
        }
    }

    return maxSequence;
}