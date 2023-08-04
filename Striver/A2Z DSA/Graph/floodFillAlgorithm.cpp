#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N*M)
        Space Complexity : O(N*M)
    */

private:
    int m, n, oldColor;
    vector<vector<bool>> visited;

    bool isValid(int i, int j, vector<vector<int>> &image)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != oldColor || visited[i][j])
            return false;

        return true;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        m = image.size(), n = image[0].size(), oldColor = image[sr][sc];

        if (newColor == oldColor)
            return image;

        visited.resize(m, vector<bool>(n, false));

        queue<pair<int, int>> q1;
        q1.push({sr, sc});
        image[sr][sc] = newColor;
        visited[sr][sc] = true;

        vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

        while (!q1.empty())
        {
            pair<int, int> curr = q1.front();
            q1.pop();

            for (auto dir : dirc)
            {
                int newX = curr.first + dir.first;
                int newY = curr.second + dir.second;

                if (isValid(newX, newY, image))
                {
                    image[newX][newY] = newColor;
                    visited[newX][newY] = true;
                    q1.push({newX, newY});
                }
            }
        }

        return image;
    }
};

int main()
{

    return 0;
}