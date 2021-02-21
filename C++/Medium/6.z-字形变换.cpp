/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(numRows==1) return s;
        for(int i=0;i<numRows;i++)
        {
            int flag=0;
            for(int j=i;j<s.length();)
            {
                result+=s[j];
                if(flag==0)
                {
                    if(2*numRows-2*(i+1)!=0)
                    {
                        j+=2*numRows-2*(i+1);
                    }
                    else
                    {
                        j+=2*i;
                    }
                    
                    flag=1;
                }
                else
                {
                    if(2*i!=0)
                    {
                        j+=2*i;
                    }
                    else
                    {
                        j+=2*numRows-2*(i+1);
                    }
                    flag=0;
                }
            }
        }
        return result;
    }
};
// @lc code=end

