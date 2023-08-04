#include "bits/stdc++.h"
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &A, int key)
{
    // Write your code here.
    int low = 0, high = A.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] == key)
            return true;
        if (A[low] == A[mid] && A[mid] == A[high])
        {
            low++;
            high--;
        }

        if (A[low] <= A[mid])
        {
            // check whether element lies in this range
            if (A[low] <= key && A[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // Right half is sorted
            if (A[mid] < key && A[high] >= key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}