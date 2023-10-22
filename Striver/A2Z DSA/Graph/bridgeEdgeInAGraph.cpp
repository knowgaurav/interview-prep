#include "bits/stdc++.h"
using namespace std;

class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        adj[c].erase(find(begin(adj[c]), end(adj[c]), d));
        adj[d].erase(find(begin(adj[d]), end(adj[d]), c));
        
        queue<int> q1;
        q1.push(c);
        vector<int> visited(V+1, 0);
        
        while(!q1.empty()){
            int front = q1.front();
            q1.pop();
            
            for(int &neighbour : adj[front]){
                if(!visited[neighbour]){
                    q1.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
        
        return !visited[d];
    }
};

class Solution {
    
    /*
        Time Complexity : O(V+E)
        Space Complexity : O(V+E)
    */
    
private:
    int timer = 0;
    vector<int> visited;
    vector<int> insertTime;
    vector<int> lowestTime;
    
    vector<vector<int>> bridges;
    
    void dfs(int node, int parent, vector<vector<int>> &adj){
        visited[node] = 1;
        insertTime[node] = lowestTime[node] = timer;
        timer++;
        
        for(int &neighbour : adj[node]){
            if(neighbour == parent) continue;
            
            if(!visited[neighbour]){
                dfs(neighbour, node, adj);
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbour]);
                
                if(lowestTime[neighbour] > insertTime[node]){
                    bridges.push_back({node, neighbour});
                }
            }else{
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbour]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int>());
        visited.resize(n, 0);
        insertTime.resize(n, 0);
        lowestTime.resize(n, 0);
        
        for(auto &it: connections){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, adj);
        
        return bridges;
    }
};

int main()
{

    return 0;
}