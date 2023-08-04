#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(m*n)
        Space Complexity : O(m*n)
    */

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;

        vector<int> res;

        while (left <= right && top <= bottom)
        {

            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            // Check if elements are left in the last row
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Check if elements are left in the last col
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};