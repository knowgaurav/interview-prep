/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    //     bool isPowerOfTwo(int n) {
    //         if(n==0)
    //             return false;

    //         while(n%2 == 0){
    //             n/=2;
    //         }

    //         return n==1 ? true : false;
    //     }
    //     bool isPowerOfTwo(int n){
    //         if(n==0)
    //             return false;

    //         while(n>1 && (n&1==0)){
    //             n>>=1;
    //         }

    //         return n==1 ? true : false;
    //     }
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;

        return floor(log2(n)) == ceil(log2(n)) ? true : false;
    }
};
// @lc code=end
