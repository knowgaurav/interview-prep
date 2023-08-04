#include "bits/stdc++.h"
using namespace std;

/*
	Memoization:
	Time Complexity : O(m*n)
	Space Complexity : O(m*n) + O(m+n)
*/

int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
	if (i < 0 || j < 0)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i] == t[j])
	{
		return dp[i][j] = 1 + helper(i - 1, j - 1, s, t, dp);
	}

	return dp[i][j] = 0 + max(helper(i - 1, j, s, t, dp), helper(i, j - 1, s, t, dp));
}

int lcs(string s, string t)
{
	// Write your code here
	int n = s.length(), m = t.length();
	vector<vector<int>> dp(n, vector<int>(m, -1));

	return helper(n - 1, m - 1, s, t, dp);
}

/*
	Tabulation:
	Time Complexity : O(m*n)
	Space Complexity : O(m*n)
*/

int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
	if (i == 0 || j == 0)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i - 1] == t[j - 1])
	{
		return dp[i][j] = 1 + helper(i - 1, j - 1, s, t, dp);
	}

	return dp[i][j] = 0 + max(helper(i - 1, j, s, t, dp), helper(i, j - 1, s, t, dp));
}

int lcs(string s, string t)
{
	// Write your code here
	int n = s.length(), m = t.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

	for (int i = 0; i < n; i++)
		dp[i][0] = 0;
	for (int j = 0; j < m; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	// Print LCS
	int i = n, j = m;
	string res = "";
	int len = dp[i][j], indx = len - 1;

	for (int k = 0; k < len; k++)
		res.push_back('$');

	while (i > 0 && j > 0)
	{
		if (s[i - 1] == t[j - 1])
		{
			res[indx] = s[i - 1];
			indx--;
			i--;
			j--;
		}
		else if (dp[i][j - 1] > dp[i - 1][j])
		{
			j--;
		}
		else
		{
			i--;
		}
	}

	cout << res << endl;

	return dp[n][m];
}

int main()
{

	return 0;
}