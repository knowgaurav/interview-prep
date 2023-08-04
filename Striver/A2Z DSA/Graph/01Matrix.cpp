#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N*M)
    Space Complexity : O(N*M)
*/

vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here.
    vector<vector<int>> res(n, vector<int>(m, -1));
    queue<pair<int, int>> q1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j])
            {
                res[i][j] = 0;
                q1.push({i, j});
            }
        }
    }

    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

    while (!q1.empty())
    {
        pair<int, int> curr = q1.front();
        q1.pop();

        for (auto dir : dirc)
        {
            int i = curr.first + dir.first;
            int j = curr.second + dir.second;

            if (i >= 0 && i < n && j >= 0 && j < m && res[i][j] == -1)
            {
                res[i][j] = 1 + res[curr.first][curr.second];
                q1.push({i, j});
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}