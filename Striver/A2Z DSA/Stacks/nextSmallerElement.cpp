#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(N^2)
    Space Complexity : O(1)
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        int minR = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < minR)
            {
                minR = arr[j];
                break;
            }
        }

        if (minR == arr[i])
            minR = -1;
        res.push_back(minR);
    }

    return res;
}

/*
    Time Complexity : O(N)
    Space Complexity : O(N)
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s1;
    s1.push(-1);
    vector<int> res;

    for (int i = n - 1; i >= 0; i--)
    {
        while (s1.top() >= arr[i])
        {
            s1.pop();
        }

        res.push_back(s1.top());
        s1.push(arr[i]);
    }

    reverse(begin(res), end(res));
    return res;
}

int main()
{

    return 0;
}