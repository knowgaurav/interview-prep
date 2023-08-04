#include "bits/stdc++.h"
using namespace std;

vector<char> getAlienLanguage(string *dictionary, int n)
{
    // Write your code here.
    vector<vector<int>> adj(26, vector<int>());
    vector<int> inDegree(26, 0);

    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];

        int minLen = min(s1.length(), s2.length());

        for (int ptr = 0; ptr < minLen; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                inDegree[s2[ptr] - 'a']++;
                break;
            }
        }
    }

    queue<int> q1;

    for (int i = 0; i < 26; i++)
    {
        if (inDegree[i] == 0)
        {
            q1.push(i);
        }
    }

    vector<char> res;
    while (!q1.empty())
    {
        int curr = q1.front();
        q1.pop();

        for (int neighbour : adj[curr])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
            {
                q1.push(neighbour);
            }
        }

        res.push_back(curr + 'a');
    }

    return res;
}

int main()
{

    return 0;
}