#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end());

    stack<vector<int>> s;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (i == 0)
            s.push(intervals[i]);
        else
        {
            vector<int> top = s.top();
            if (intervals[i][0] > top[1])
                s.push(intervals[i]);
            else
            {
                s.pop();
                s.push({top[0], max(top[1], intervals[i][1])});
            }
        }
    }

    stack<vector<int>> reversed;

    while (!s.empty())
    {
        reversed.push(s.top());
        s.pop();
    }

    vector<vector<int>> ans;

    while (!reversed.empty())
    {
        ans.push_back(reversed.top());
        reversed.pop();
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
}