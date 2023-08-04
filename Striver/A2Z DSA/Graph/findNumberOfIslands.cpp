#include "bits/stdc++.h"
using namespace std;

class Solution {
  private:
    int m, n;
    vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {-1, -1}, {+1, +1}, {-1, +1}, {+1, -1}};
    
    void dfs(int i, int j, vector<vector<char>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        
        for(auto dir : dirc){
            int newX = i + dir.first;
            int newY = j + dir.second;
            
            dfs(newX, newY, grid);
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int res = 0;
        m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(i, j, grid);
                    res++;
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