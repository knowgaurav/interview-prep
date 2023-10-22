#include "bits/stdc++.h"
using namespace std;

class Solution {
  private:
    vector<int> visited;
    vector<int> insertTime;
    vector<int> lowestTime;
    vector<int> mark;
    int timer = 0;
    
    void dfs(int node, int parent, vector<int> adj[]){
        visited[node] = 1;
        insertTime[node] = lowestTime[node] = timer;
        timer++;
        
        int child = 0;
        
        for(int &neighbour : adj[node]){
            if(neighbour == parent) continue;
            
            if(!visited[neighbour]){
                dfs(neighbour, node, adj);
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbour]);
                
                if(lowestTime[neighbour]>=insertTime[node] && parent!=-1){
                    mark[node] = 1;
                }
                
                child++;
            }else{
               lowestTime[node] = min(lowestTime[node], insertTime[neighbour]); 
            }
        }
        
        if(child>1 && parent==-1){
            mark[node] = 1;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        visited.resize(V+1, 0);
        insertTime.resize(V+1, 0);
        lowestTime.resize(V+1, 0);
        mark.resize(V+1, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, -1, adj);
            }
        }
        
        vector<int> res;
        
        for(int i=0; i<V; i++){
            if(mark[i] == 1){
                res.push_back(i);
            }
        }
        
        if(res.size() == 0) return {-1};
        return res;
    }
};

int main()
{

    return 0;
}