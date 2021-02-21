/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0) return false;
        double temp=log(num)/log(4);
        if(temp-(int)temp<1e-10) return true;
        else return false;
    }
};
// @lc code=end

