#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

void dfs(int i, int j, vector<vector<int>> &Matrix)
{
    if (i >= 0 && i < Matrix.size() && j >= 0 && j < Matrix[0].size() && Matrix[i][j] == 0)
    {

        Matrix[i][j] = 2;

        for (auto dir : dirc)
        {
            int newX = i + dir.first;
            int newY = j + dir.second;

            dfs(newX, newY, Matrix);
        }
    }
}

int matrixTraps(int N, int M, vector<vector<int>> &Matrix)
{
    // Write your code here.
    for (int i = 0; i < N; i++)
    {
        if (Matrix[i][0] == 0)
            dfs(i, 0, Matrix);
        if (Matrix[i][M - 1] == 0)
            dfs(i, M - 1, Matrix);
    }

    for (int j = 0; j < M; j++)
    {
        if (Matrix[0][j] == 0)
            dfs(0, j, Matrix);
        if (Matrix[N - 1][j] == 0)
            dfs(N - 1, j, Matrix);
    }

    int res = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Matrix[i][j] == 0)
                res++;
        }
    }

    return res;
}

int main()
{

    return 0;
}