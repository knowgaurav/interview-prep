/*
 * @lc app=leetcode id=547 lang=java
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
    public void dfs(int[][] M, int i){
        if(M[i][i] == 0)    return;

        for(int j=0; j<M[0].length; j++){
            if(M[i][j] == 1){
                M[i][j] = M[j][i] = 0;
                dfs(M, j);
            }
        }
    }

    public int findCircleNum(int[][] M) {
        int count = 0;

        for(int i=0; i<M.length; i++){
            if(M[i][i] == 1){
                dfs(M, i);
                count++;
            }
        }

        return count;
    }
}
// @lc code=end

