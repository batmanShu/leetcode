/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int reverse_x=0;
        int temp=x;
        while(temp!=0)
        {
            if(reverse_x>INT_MAX/10) return false;
            reverse_x=reverse_x*10+temp%10;
            temp=temp/10;
        }
        return (reverse_x-x==0)?true:false;
    }
};
// @lc code=end

