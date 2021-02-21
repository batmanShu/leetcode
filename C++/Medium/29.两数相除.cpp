/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        if(dividend==0) return 0;
        int sign=(dividend<0)^(divisor<0)?-1:1;
        long x=(dividend<0)? -(long)dividend:(long)dividend;
        long y=(divisor<0)? -(long)divisor:(long)divisor;
        long result=0;
        while(x>=y)
        {
            long temp=y,mid=1;
            while(x>=temp<<1)
            {
                temp<<=1;
                mid<<=1;
            }
            x-=temp;
            result+=mid;
        }
        return sign>0? result:-result;
    }
};
// @lc code=end

