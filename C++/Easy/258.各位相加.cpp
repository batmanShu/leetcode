/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        int result=0;
        while(num!=0)
        {
            result=result+num%10;
            num=num/10;
        }
        if(result<10) return result;
        else return addDigits(result);
    }
};
// @lc code=end

