#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N*4)*3
    Space Complexity : O(N*4)
*/

int helper(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        // If lastTask day just return the max of the remaining days - base case
        int maxActivity = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != lastTask)
            {
                maxActivity = max(maxActivity, points[day][task]);
            }
        }
        return maxActivity;
    }

    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];

    int maxActivity = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != lastTask)
        {
            maxActivity = max(maxActivity, points[day][task] + helper(day - 1, task, points, dp));
        }
    }
    return dp[day][lastTask] = maxActivity;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // day, lastTask, points, dp
    helper(n - 1, 3, points, dp);

    return dp[n - 1][3];
}

/*
    Time Complexity : O(N*4)*3
    Space Complexity : O(N*4)
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int lastTask = 0; lastTask <= 3; lastTask++)
        {
            int maxPoints = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != lastTask)
                {
                    maxPoints = max(maxPoints, points[day][task] + dp[day - 1][task]);
                }
            }

            dp[day][lastTask] = maxPoints;
        }
    }

    return dp[n - 1][3];
}

int main()
{

    return 0;
}