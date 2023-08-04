#include <bits/stdc++.h>

using namespace std;

long long merge(vector<long long> &arr, long long left, long long mid, long long right)
{
    long long i = left;
    long long j = mid + 1;
    long long k = mid;
    vector<long long> temp;
    long long inversion_count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            inversion_count += (mid - i) + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    long long x = 0;
    for (int i = left; i <= right; i++)
        arr[i] = temp[x++];

    return inversion_count;
}

long long mergeSort(vector<long long> &arr, long long left, long long right)
{
    long long mid, inversion_count = 0;
    if (left < right)
    {
        mid = (left + right) / 2;

        inversion_count += mergeSort(arr, left, mid);
        inversion_count += mergeSort(arr, mid + 1, right);
        inversion_count += merge(arr, left, mid, right);
    }
    return inversion_count;
}

// int countInversions(vector<int> &arr)
long long int inversionCount(long long arr[], long long N)
{
    vector<long long> arr1;
    for (long long i = 0; i < N; i++)
        arr1.push_back(arr[i]);

    return mergeSort(arr1, 0, arr1.size() - 1);
}

int main()
{
    // vector<long long> arr{2, 3, 4, 5, 6};
    long long arr[] = {2, 3, 4, 5, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);
    cout << "No. of inversions are: " << inversionCount(arr, n);

    cout << "\n\nSorted array: ";
    for (long long i : arr)
        cout << i << " ";
    return 0;
}