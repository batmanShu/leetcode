/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long end=num;
        long begin=0;
        long mid;
        while (begin<=end)
        {
            mid=(begin+end)/2;
            if(mid*mid>num) end=mid-1;
            else if(mid*mid<num) begin=mid+1;
            else return true;
        }
        return false;
    }
};
// @lc code=end

