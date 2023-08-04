#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N*M)
    Space Complexity : O(N*M)
*/

int row[] = {+1, -1, 0, 0};
int col[] = {0, 0, +1, -1};

void dfs(char **arr, int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 'O')
    {
        arr[i][j] = 'Z';

        for (int k = 0; k < 4; k++)
        {
            int newX = i + row[k];
            int newY = j + col[k];

            dfs(arr, newX, newY, n, m);
        }
    }
}

void replaceOWithX(char **arr, int n, int m)
{
    // Write your code here

    // Boundary DFS
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 'O')
            dfs(arr, i, 0, n, m);
        if (arr[i][m - 1] == 'O')
            dfs(arr, i, m - 1, n, m);
    }

    for (int j = 0; j < m; j++)
    {
        if (arr[0][j] == 'O')
            dfs(arr, 0, j, n, m);
        if (arr[n - 1][j] == 'O')
            dfs(arr, n - 1, j, n, m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'O')
            {
                arr[i][j] = 'X';
            }
            else if (arr[i][j] == 'Z')
            {
                arr[i][j] = 'O';
            }
        }
    }
}

int main()
{

    return 0;
}