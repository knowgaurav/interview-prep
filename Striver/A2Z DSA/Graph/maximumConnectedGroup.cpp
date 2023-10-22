#include "bits/stdc++.h"
using namespace std;

class DisjointSet{
    private:
    vector<int> parent;
    vector<int> size;
    
    public:
    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int uParent = findUltimateParent(u);
        int vParent = findUltimateParent(v);
        
        if(uParent == vParent) return;
        
        if(size[uParent] < size[vParent]){
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }else{
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
    
    int getSize(int node){
        return size[node];
    }
};

class Solution {
    
    int xDir[4] = {+1, -1, 0, 0};
    int yDir[4] = {0, 0, +1, -1};
    
    bool isValid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        
        DisjointSet ds(n*m);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int node = (i*m) + j;
                    
                    for(int d=0; d<4; d++){
                        int newX = i + xDir[d];
                        int newY = j + yDir[d];
                        
                        if(isValid(newX, newY, n, m) && grid[newX][newY] == 1){
                            int adjNode = (newX*m) + newY;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<n*m; i++){
            res = max(res, ds.getSize(i));
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> parents;
                    
                    for(int d=0; d<4; d++){
                        int newX = i + xDir[d];
                        int newY = j + yDir[d];
                        
                        if(isValid(newX, newY, n, m) && grid[newX][newY] == 1){
                            int adjNode = (newX*m) + newY;
                            parents.insert(ds.findUltimateParent(adjNode));
                        }
                    }
                    
                    int totalSize = 0;
                    for(int p : parents){
                        totalSize += ds.getSize(p);
                    }
                    
                    res = max(res, totalSize + 1);
                }
            }
        }
        
        return res;
    }
};

int main()
{

    return 0;
}