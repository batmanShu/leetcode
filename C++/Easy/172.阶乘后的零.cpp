/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        while(n!=0)
        {
            n=n/5;
            result=result+n;
        }
        return result;
    }
};
