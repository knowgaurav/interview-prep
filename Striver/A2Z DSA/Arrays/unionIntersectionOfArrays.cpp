// Union of two arrays can be defined as the common and distinct elements in the two arrays.
// Given two sorted arrays of size n and m respectively, find their union.

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Your code here
        // return vector with correct order of elements
        int i, j;
        i = j = 0;

        vector<int> res;

        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (res.size() == 0 || res.back() != arr1[i])
                    res.push_back(arr1[i]);

                i++;
            }
            else
            {
                if (res.size() == 0 || res.back() != arr2[j])
                    res.push_back(arr2[j]);

                j++;
            }
        }

        while (i < n)
        {
            if (res.size() == 0 || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }

        while (j < m)
        {
            if (res.size() == 0 || res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }

        return res;
    }

    vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
    {
        // Write your code here.
        vector<int> res;
        vector<bool> visited(m, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr1[i] == arr2[j] && !visited[j])
                {
                    res.push_back(arr1[i]);
                    visited[j] = true;
                    break;
                }

                if (arr2[j] > arr1[i])
                    break;
            }
        }

        return res;
    }
};
