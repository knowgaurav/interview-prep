/*
 * @lc app=leetcode id=1305 lang=java
 *
 * [1305] All Elements in Two Binary Search Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> ans = new ArrayList<>();
        if(root1 == null && root2 == null)  return ans;
        
        List<Integer> arr1 = new ArrayList<>();
        inorder(root1, arr1);
        List<Integer> arr2 = new ArrayList<>();
        inorder(root2, arr2);
        
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1.get(i) < arr2.get(j)){
                ans.add(arr1.get(i));
                i++;
            }
            else{
                ans.add(arr2.get(j));
                j++;
            }
        }
        
        while(i<arr1.size()){
            ans.add(arr1.get(i));
            i++;
        }
        
        while(j<arr2.size()){
            ans.add(arr2.get(j));
            j++;
        }
        
        return ans;
    }
    
    private void inorder(TreeNode root, List<Integer> arr){
        if(root==null) return;
        inorder(root.left, arr);
        arr.add(root.val);
        inorder(root.right, arr);
    }
}
// @lc code=end

