/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_len=haystack.size();
        int n_len=needle.size();
        if(h_len<n_len) return -1;
        if(h_len==0||n_len==0) return 0;
        for(int i=0;i<h_len;i++)
        {
            if(haystack[i]==needle[0])
            {
                for(int j=0;j<n_len;j++)
                {
                    if(haystack[i+j]!=needle[j]) break;
                    if(j==n_len-1) return i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

