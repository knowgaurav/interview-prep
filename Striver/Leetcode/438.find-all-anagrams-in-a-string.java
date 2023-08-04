/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int st = 0;
        int en = p.length()-1;
        
        List<Integer> ans = new ArrayList<Integer>();
        
        if(p.length() > s.length() || en<0)
            return ans;
        
        HashMap<Character, Integer> hmap1 = new HashMap<>();
        HashMap<Character, Integer> hmap2 = new HashMap<>();
        
        for(int i=0; i<p.length(); i++){
            char ch = p.charAt(i);
            hmap2.put(ch, hmap2.getOrDefault(ch, 0) + 1);
        }
        
        for(int i=0; i<=en; i++){
            char ch = s.charAt(i);
            hmap1.put(ch, hmap1.getOrDefault(ch, 0) + 1);
        }
        
        if(hmap2.equals(hmap1))
            ans.add(st);
        
        st++;
        en++;
        
        while(en < s.length()){
            //add next char
            char ch = s.charAt(en);
            hmap1.put(ch, hmap1.getOrDefault(ch, 0) + 1);
            
            //remove previous char
            ch = s.charAt(st-1);
            if(hmap1.containsKey(ch)){
                hmap1.put(ch, hmap1.get(ch)-1);
                
                if(hmap1.get(ch) == 0)
                    hmap1.remove(ch);
            }
            
            if(hmap2.equals(hmap1))
                ans.add(st);
            
            st++;
            en++;
        }
        
        return ans;
    }
}
// @lc code=end

