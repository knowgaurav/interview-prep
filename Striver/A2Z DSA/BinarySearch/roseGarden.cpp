#include "bits/stdc++.h"
using namespace std;

int isPossbile(int day, vector<int> &arr, int k)
{
    int res = 0, counter = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            counter++;
        }
        else
        {
            res += counter / k;
            counter = 0;
        }
    }

    res += counter / k;
    return res;
}

int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    if (m * k > arr.size())
        return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    for (int i = low; i <= high; i++)
    {
        if (isPossbile(i, arr, k) >= m)
            return i;
    }

    return -1;
}

int main()
{

    return 0;
}