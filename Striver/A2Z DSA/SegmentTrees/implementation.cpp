#include "bits/stdc++.h"
using namespace std;

void buildSegmentTree(int idx, int low, int high, vector<int> &arr, vector<int> &segmentTreeArr)
{
    if (low == high)
    {
        segmentTreeArr[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    buildSegmentTree(2 * idx + 1, low, mid, arr, segmentTreeArr);
    buildSegmentTree(2 * idx + 2, mid + 1, high, arr, segmentTreeArr);
    segmentTreeArr[idx] = min(segmentTreeArr[2 * idx + 1], segmentTreeArr[2 * idx + 2]);
}

int findMinQuery(int idx, int low, int high, vector<int> &segmentTreeArr, int l, int h)
{
    // No overlap - [l, h][low, high] or [low, high][l, h]
    if (h < low or high < l)
    {
        return INT_MAX;
    }

    // Complete overlap - [l low high h]
    if (l <= low and h >= high)
    {
        return segmentTreeArr[idx];
    }

    // Partial Overlap
    int mid = (low + high) / 2;
    int left = findMinQuery(2 * idx + 1, low, mid, segmentTreeArr, l, h);
    int right = findMinQuery(2 * idx + 2, mid + 1, high, segmentTreeArr, l, h);
    return min(left, right);
}

void updateSegmentTree(int idx, int low, int high, vector<int> &segmentTreeArr, int i, int val)
{
    if (low == high)
    {
        segmentTreeArr[idx] = val;
        return;
    }

    int mid = (low + high) / 2;
    if (i <= mid)
        updateSegmentTree(2 * idx + 1, low, mid, segmentTreeArr, i, val);
    else
        updateSegmentTree(2 * idx + 2, mid + 1, high, segmentTreeArr, i, val);
    segmentTreeArr[idx] = min(segmentTreeArr[2 * idx + 1], segmentTreeArr[2 * idx + 2]);
}

int main()
{
    int n = 6;
    vector<int> arr = {2, 5, 1, 4, 9, 3};
    vector<int> segmentTreeArr(4 * n, 0);

    buildSegmentTree(0, 0, 5, arr, segmentTreeArr);

    // for (int i = 0; i < 6; i++)
    //     cout << segmentTreeArr[i] << " ";

    // cout << "Minimum in the range [3-5] is : " << findMinQuery(0, 0, 5, segmentTreeArr, 3, 5) << endl;
    cout << "Minimum in the range [1-5] is : " << findMinQuery(0, 0, 5, segmentTreeArr, 1, 5) << endl;

    updateSegmentTree(0, 0, 5, segmentTreeArr, 2, 0);

    cout << "Minimum in the range [1-5] is : " << findMinQuery(0, 0, 5, segmentTreeArr, 1, 5) << endl;

    return 0;
}