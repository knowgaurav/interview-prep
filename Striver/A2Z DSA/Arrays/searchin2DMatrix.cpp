#include <bits/stdc++.h>

using namespace std;

pair<int, int> search2DMatrix(vector<vector<int>> matrix, int target)
{
    if (matrix.size() == 0)
        return {0, 0};

    int m = matrix.size(), n = matrix[0].size();

    int i = 0;
    int j = (m * n) - 1;

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (matrix[mid / m][mid % m] == target)
            return {mid / m, mid % m};
        else if (matrix[mid / m][mid % m] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }

    return {0, 0};
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    pair<int, int> idx = search2DMatrix(arr, 10);

    cout << "Target found @: " << idx.first << ", " << idx.second;

    return 0;
}