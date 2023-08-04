#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        // code here
        vector<vector<int>> res(n, vector<int>(n, 0));

        // 0, 0 -> 2, 0
        // 0, 1 -> 1, 0
        // 0, 2 -> 0, 0

        // 1, 0 -> 2, 1
        // 1, 1 -> 1, 1
        // 1, 2 -> 0, 1

        // j = i
        // i = (n-1)-j

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[(n - 1) - j][i] = matrix[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = res[i][j];
            }
        }
    }
};
