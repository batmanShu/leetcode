/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */
class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            int temp=(int) s[len-i-1];
            temp=temp-64;
            result=result+temp*pow(26,i);
        }
        return result;
    }
};

