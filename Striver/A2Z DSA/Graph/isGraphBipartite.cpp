#include "bits/stdc++.h"
using namespace std;

#include <queue>

bool check(int node, vector<vector<int>> &edges, vector<int> &color)
{
    queue<int> q1;
    q1.push(node);
    color[node] = 0;

    while (!q1.empty())
    {
        int curr = q1.front();
        q1.pop();

        for (int k = 0; k < edges[curr].size(); k++)
        {
            if (edges[curr][k])
            {
                if (color[k] == -1)
                {
                    color[k] = !color[curr];
                    q1.push(k);
                }
                else if (color[k] == color[curr])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int V = edges[0].size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!check(i, edges, color))
                return false;
        }
    }

    return true;
}

bool checkDFS(int node, int color, vector<vector<int>> &edges, vector<int> &colors)
{
    colors[node] = color;

    for (int k = 0; k < edges[node].size(); k++)
    {
        if (edges[node][k])
        {
            if (colors[k] == -1)
            {
                return checkDFS(k, !color, edges, colors);
            }
            else if (colors[k] == colors[node])
            {
                return false;
            }
        }
    }

    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int V = edges[0].size();
    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (colors[i] == -1)
        {
            if (!checkDFS(i, 0, edges, colors))
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}