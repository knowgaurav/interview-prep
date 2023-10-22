#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(V+E)
    Space Complexity : O(V+E)
*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> maxTime(n+1, 0);
        vector<int> inDegree(n+1, 0);
        unordered_map<int, vector<int>> adj(n+1);
        
        for(int i=0; i<relations.size(); i++){
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q1;
        
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q1.push(i);
                maxTime[i] = time[i];
            }
        }
        
        while(!q1.empty()){
            int front = q1.front();
            q1.pop();
            
            for(int &neighbour : adj[front]){
                maxTime[neighbour] = max(maxTime[neighbour], time[neighbour] + maxTime[front]);
                
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0){
                    q1.push(neighbour);
                }
            }
        }
        
        return *max_element(begin(maxTime), end(maxTime));
    }
};

int main()
{

    return 0;
}