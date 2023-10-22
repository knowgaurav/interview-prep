#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(100000 *n)
    Space Complexity : O(100000)
*/

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q1;

        q1.push({start, 0});
        dist[start] = 0;
        int mod = 100000;

        while (!q1.empty())
        {
            int num = q1.front().first;
            int steps = q1.front().second;
            q1.pop();

            for (int n : arr)
            {
                int neighbour = (num * n) % mod;

                if (dist[neighbour] > steps + 1)
                {
                    dist[neighbour] = steps + 1;
                    q1.push({neighbour, steps + 1});
                }
            }
        }

        if (dist[end] == INT_MAX)
            return -1;

        return dist[end];
    }
};

int main()
{

    return 0;
}