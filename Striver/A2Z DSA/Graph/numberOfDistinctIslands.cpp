#include "bits/stdc++.h"
using namespace std;

int row[] = {+1, -1, 0, 0};
int col[] = {0, 0, +1, -1};
int order[] = {'D', 'U', 'R', 'L'};

bool isValid(int i, int j, int **arr, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 1)
        return true;

    return false;
}

string dfs(int i, int j, int **arr, int n, int m)
{
    string ans = "X";
    arr[i][j] = 2;

    for (int k = 0; k < 4; k++)
    {
        int newX = i + row[k];
        int newY = j + col[k];

        if (isValid(newX, newY, arr, n, m))
        {
            string temp = dfs(newX, newY, arr, n, m);
            ans += order[k];
            ans += temp;
        }
        else
        {
            ans += 'O';
        }
    }

    return ans;
}

int distinctIslands(int **arr, int n, int m)
{
    // Write your code here
    set<string> res;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                res.insert(dfs(i, j, arr, n, m));
            }
        }
    }

    return res.size();
}

int main()
{

    return 0;
}