#include "bits/stdc++.h"
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> s1;
    int res = 0, n = heights.size();

    for (int i = 0; i <= n; i++)
    {
        while (!s1.empty() and (i == n || heights[s1.top()] >= heights[i]))
        {
            int len = heights[s1.top()];
            s1.pop();

            int bre;
            if (s1.empty())
                bre = i;
            else
                bre = i - s1.top() - 1;
            res = max(res, len * bre);
        }

        s1.push(i);
    }

    return res;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here.
    vector<int> temp(m, 0);
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[j] = mat[i][j] == 0 ? 0 : (temp[j] + mat[i][j]);
        }

        int area = largestRectangleArea(temp);
        res = max(res, area);
    }

    return res;
}

int main()
{

    return 0;
}