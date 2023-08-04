#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int> arr, int size)
{
    int majority = 0;
    int count = 1;

    for (int i = 1; i < size; i++)
    {
        if (arr[majority] == arr[i])
            count++;
        else
            count--;

        if (count == 0)
        {
            count = 1;
            majority = i;
        }
    }

    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == arr[majority])
            count++;

    return (count > size / 2) ? majority : -1;

    //         if(nums.size() == 1)
    //             return nums[0];

    //         sort(nums.begin(), nums.end());

    //         int n = nums.size()/2;
    //         int ele;
    //         for(int i=0; i<nums.size()-n; i++){
    //             if(nums[i] == nums[i+n]){
    //                 ele = nums[i];
    //             }
    //         }

    //         return ele;
    // int count = 0;
    // int candidate = 0;

    // for (int num : nums) {
    //     if (count == 0)
    //         candidate = num;

    //     if(num==candidate) count += 1;
    //     else count -= 1;
    // }

    // return candidate;
}

// Majority Element 2
vector<int> majorityElement2(vector<int> &nums)
{
    int sz(nums.size());
    int num1(-1), num2(-1), c1(0), c2(0);

    for (int i = 0; i < sz; i++)
    {
        if (num1 == nums[i])
            c1++;
        else if (num2 == nums[i])
            c2++;
        else if (c1 == 0)
        {
            num1 = nums[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = nums[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    vector<int> ans;
    c1 = c2 = 0;

    for (int i = 0; i < sz; i++)
        if (num1 == nums[i])
            c1++;
        else if (num2 == nums[i])
            c2++;

    if (c1 > sz / 3)
        ans.push_back(num1);
    if (c2 > sz / 3)
        ans.push_back(num2);

    return ans;
}

int main()
{
    vector<int> arr = {8, 8, 8, 6, 6, 4, 6};

    cout << "Majority Element is: " << arr[majorityElement(arr, arr.size())] << endl;
    cout << "Majority Element 2 is: " << majorityElement2(arr)[0] << " " << majorityElement2(arr)[1];

    return 0;
}