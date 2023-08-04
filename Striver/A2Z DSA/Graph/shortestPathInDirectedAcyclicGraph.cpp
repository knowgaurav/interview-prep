#include "bits/stdc++.h"
using namespace std;

/*
    Using Topological Sorting: 
    Time Complexity : O(N + M)
    Space Complexity : O(N + M)
*/

void topoSortDFS(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour.first]){
            topoSortDFS(neighbour.first, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
    }

    vector<bool> visited(n, false);
    stack<int> st;

    topoSortDFS(0, adj, visited, st);


    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    while(!st.empty()){
        int curr = st.top();
        st.pop();

        for(auto neighbour : adj[curr]){
            int v = neighbour.first;
            int wt = neighbour.second;

            if(dist[curr]+wt<dist[v]){
                dist[v] = dist[curr] + wt;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    
    return dist;
}


int main()
{

    return 0;
}