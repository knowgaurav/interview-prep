#include "bits/stdc++.h"
using namespace std;

void dfs(int curr_road, vector<bool> &visited, vector<vector<int>>& roads){
    int n = roads.size();
    visited[curr_road] = true;

    for(int i=0; i<n; i++){
        if(i==curr_road) continue;

        if(!visited[i] && roads[curr_road][i]){
            dfs(i, visited, roads);
        }
    }
}

int findNumOfStates(vector<vector<int>>& roads, int n) {
    // Write your code here.
    int ans = 0;
    vector<bool> visited(n, false);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, visited, roads);
            ans++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}