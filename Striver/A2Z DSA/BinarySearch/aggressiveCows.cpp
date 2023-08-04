#include "bits/stdc++.h"
using namespace std;

bool canBePlaced(vector<int> &stalls, int dist, int cows)
{
    int countCows = 1, last = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            last = stalls[i];
            countCows++;
        }
    }

    if (countCows >= cows)
        return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(begin(stalls), end(stalls));
    int low = 1, high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canBePlaced(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{

    return 0;
}