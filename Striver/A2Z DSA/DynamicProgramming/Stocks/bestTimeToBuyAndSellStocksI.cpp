#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int minLeft = prices[0], res = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        int profit = prices[i] - minLeft;
        minLeft = min(minLeft, prices[i]);
        res = max(res, profit);
    }

    return res;
}

int main()
{

    return 0;
}