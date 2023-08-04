#include "bits/stdc++.h"
using namespace std;

int helper(int num, int times)
{
    int res = 1;
    for (int i = 1; i <= times; i++)
    {
        res *= num;
    }
    return res;
}

int NthRoot(int n, int m)
{
    // Write your code here.
    for (int i = 1; i <= m; i++)
    {
        if (helper(i, n) == m)
        {
            return i;
        }
        else if (helper(i, n) > m)
            break;
    }

    return -1;
}

int helper(int mid, int n, int m)
{
    long long res = 1;
    for (int t = 1; t <= n; t++)
    {
        res *= mid;
        if (res > m)
            return 2;
    }

    if (res == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (helper(mid, n, m) == 1)
        {
            return mid;
        }
        else if (helper(mid, n, m) == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}