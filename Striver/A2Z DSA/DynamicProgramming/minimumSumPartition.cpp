#include "bits/stdc++.h"
using namespace std;

class Solution
{

public:
	int minDifference(int arr[], int n)
	{
		// Your code goes here
		int sum = accumulate(arr, arr + n, 0);
		vector<bool> prev(sum + 1, false);
		prev[0] = true;
		if (arr[0] <= sum)
			prev[arr[0]] = true;

		for (int idx = 1; idx < n; idx++)
		{
			vector<bool> curr(sum + 1, false);
			curr[0] = true;

			for (int target = 1; target <= sum; target++)
			{
				bool notTake = prev[target];
				bool take = false;
				if (arr[idx] <= target)
					take = prev[target - arr[idx]];

				curr[target] = take or notTake;
			}

			prev = curr;
		}

		int res = INT_MAX;

		for (int i = 0; i <= sum / 2; i++)
		{
			if (prev[i] == true)
			{
				res = min(res, abs(i - (sum - i)));
			}
		}

		return res;
	}
};

int main()
{

	return 0;
}