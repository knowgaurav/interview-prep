#include "bits/stdc++.h"
using namespace std;

bool checkArraySorted(int idx, vector<int> &arr)
{
    if (idx >= arr.size() - 1)
    {
        return true;
    }

    return arr[idx + 1] >= arr[idx] and checkArraySorted(idx + 1, arr);
}

int main()
{
    vector<int> arr = {1, 2, 3, 9, 5};
    cout << checkArraySorted(0, arr);
    return 0;
}