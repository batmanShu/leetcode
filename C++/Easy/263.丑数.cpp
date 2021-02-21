/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
        if(num==1) return true;
        if(num%2==0)
        {
            if(num/2==1||num/2==2||num/2==3||num/2==5)
            {
                return true;
            }
            else
            {
                return isUgly(num/2);
            }
        }
        else if(num%3==0)
        {
            if(num/3==1||num/3==3||num/3==5)
            {
                return true;
            }
            else
            {
                return isUgly(num/3);
            }
        }
        else if(num%5==0)
        {
            if(num/5==1||num/5==5)
            {
                return true;
            }
            else
            {
                return isUgly(num/5);
            }
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end

