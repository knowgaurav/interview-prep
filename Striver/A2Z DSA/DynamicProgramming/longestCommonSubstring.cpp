#include "bits/stdc++.h"
using namespace std;

int lcs(string &str1, string &str2)
{
	//	Write your code here.
	int n = str1.length(), m = str2.length();
	vector<vector<int>> dp(n, vector<int>(m, 0));

	int res = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i][j] = 1;
				if (i > 0 and j > 0)
					dp[i][j] += dp[i - 1][j - 1];
				res = max(res, dp[i][j]);
			}
		}
	}

	return res;
}

int main()
{

	return 0;
}
