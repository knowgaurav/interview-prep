#include "bits/stdc++.h"
using namespace std;

class Solution
{

    /*
        Time Complexity : O(N^2)
        Space Complexity : O(1)
    */

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0, n = heights.size();

        for (int i = 0; i < n; i++)
        {
            int curr = heights[i], breadth = 1;

            for (int j = i + 1; j < n; j++)
            {
                if (heights[j] >= curr)
                    breadth++;
                else
                    break;
            }

            for (int j = i - 1; j >= 0; j--)
            {
                if (heights[j] >= curr)
                    breadth++;
                else
                    break;
            }

            int area = curr * breadth;
            res = max(res, area);
        }

        return res;
    }
};

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(N)
    */

private:
    int n;

    void getNextSmallerIdx(vector<int> &res, vector<int> &heights)
    {
        stack<int> s1;
        s1.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (s1.top() != -1 and heights[s1.top()] >= curr)
            {
                s1.pop();
            }

            res[i] = s1.top();
            s1.push(i);
        }
    }

    void getPrevSmallerIdx(vector<int> &res, vector<int> &heights)
    {
        stack<int> s1;
        s1.push(-1);

        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (s1.top() != -1 and heights[s1.top()] >= curr)
            {
                s1.pop();
            }

            res[i] = s1.top();
            s1.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        n = heights.size();
        int res = 0;
        vector<int> nextSmaller(n), prevSmaller(n);

        getNextSmallerIdx(nextSmaller, heights);
        getPrevSmallerIdx(prevSmaller, heights);

        for (int i = 0; i < n; i++)
        {
            int currL = heights[i];
            if (nextSmaller[i] == -1)
                nextSmaller[i] = n;

            int currB = nextSmaller[i] - prevSmaller[i] - 1;
            int area = currL * currB;
            res = max(area, res);
        }

        return res;
    }
};

class Solution
{

    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */

public:
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
};

int main()
{

    return 0;
}