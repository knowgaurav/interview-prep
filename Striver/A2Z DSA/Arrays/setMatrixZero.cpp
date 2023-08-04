#include "bits/stdc++.h"
using namespace std;

// Brute Force

/*
    Time Complexity : O((m*n)*(m+n)) + O(m*n)
    Space Complexity : O(m*n)
*/

class Solution
{
private:
    int m, n;

    void makeRowZero(vector<vector<int>> &matrix, vector<vector<bool>> &mark, int i)
    {
        for (int k = 0; k < n; k++)
        {
            if (matrix[i][k])
                mark[i][k] = -1;
        }
    }

    void maxColZero(vector<vector<int>> &matrix, vector<vector<bool>> &mark, int j)
    {
        for (int k = 0; k < m; k++)
        {
            if (matrix[k][j])
                mark[k][j] = -1;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> mark(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    makeRowZero(matrix, mark, i);
                    maxColZero(matrix, mark, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mark[i][j])
                    matrix[i][j] = 0;
            }
        }
    }
};

// Better Approach

/*
    Time Complexity : O(m*n) + O(m*n)
    Space Complexity : O(m+n)
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();

        vector<bool> markRow(m, false);
        vector<bool> markCol(n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markRow[i] = true;
                    markCol[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (markRow[i] || markCol[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Optimal Approach

/*
    Time Complexity = O(m*n) + O(m*n) + O(m) + O(n)
    Space Complexity = O(1)
*/

#include <bits/stdc++.h>
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // Write your code here.
    int col0 = 1;

    // int col[m] => matrix[0][....]
    // int row[n] => matrix[....][0]

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // isse hum pehle row ke liye pehle column mark kar rahe hai
                matrix[i][0] = 0;

                // isse hum col ke liye pehla row mark kar rahe hai
                if (j == 0)
                {
                    col0 = 0;
                }
                else
                {
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}