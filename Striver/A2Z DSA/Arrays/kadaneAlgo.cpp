#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &arr, vector<int> &subArray)
{
    int n = arr.size(), maxSum = 0;

    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];

            if (sum > maxSum)
            {
                subArray.clear();
                maxSum = sum;
                subArray.push_back(i);
                subArray.push_back(j);
            }
        }

    return maxSum;
}

int kadaneAlgo(vector<int> &arr)
{
    int maxSum = INT_MIN, currSum = 0;

    if (arr.size() == 1)
        return arr[0];

    for (int i : arr)
    {
        if (currSum >= 0)
            currSum += i;
        else
            currSum = i;

        if (maxSum < currSum)
            maxSum = currSum;
    }

    return maxSum;
}

int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray;
    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;

    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nMax Sum using Kadane's Algorithm = " << kadaneAlgo(arr);
}