#include "bits/stdc++.h"
using namespace std;

// Brute Force
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int i = 0, num = 1;

        while (i < arr.size() && k > 0)
        {
            if (arr[i] == num)
            {
                i++; // not missing
            }
            else
            {
                k--;
            }

            num++;
        }

        while (k--)
            num++;

        return --num;
    }
};

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int kitne_missing_till_mid = arr[mid] - (mid + 1);

            if (kitne_missing_till_mid < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low + k;
    }
};

int main()
{

    return 0;
}