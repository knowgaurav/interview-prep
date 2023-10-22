#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(ElogV) == O(n*m*4log(m*n))
    Space Complexity : O(m*n)
*/

class Solution
{
private:
    typedef pair<int, pair<int, int>> P;
    int m, n;

    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

    bool isValid(int i, int j)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        // Code here
        m = heights.size(), n = heights[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!pq.empty())
        {
            P curr = pq.top();
            int diff = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return effort[x][y];

            for (auto dir : dirc)
            {
                int newX = dir.first + x;
                int newY = dir.second + y;

                if (isValid(newX, newY))
                {
                    int newEffort = max(abs(heights[x][y] - heights[newX][newY]), diff);

                    if (newEffort < effort[newX][newY])
                    {
                        effort[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{

    return 0;
}