/*
 * @lc app=leetcode id=40 lang=java
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
    List<List<Integer>> ans;
    int [] nums;

    private void findSubsequences(int idx, int target, List<Integer> temp){
        if(target==0){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i=idx; i<nums.length; i++){
            if(i>idx && nums[i]==nums[i-1])
                continue;
            if(nums[i] > target)
                break;

            temp.add(nums[i]);
            findSubsequences(i+1, target-nums[i], temp);
            temp.remove(temp.size()-1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        this.ans = new ArrayList<>();
        Arrays.sort(candidates);
        this.nums = candidates;

        findSubsequences(0, target, new ArrayList<>());

        return ans;
    }
}
// @lc code=end

