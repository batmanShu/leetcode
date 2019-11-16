/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret="";
        if(strs.empty()) return ret;
        int minsize=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()<minsize) minsize=strs[i].size();
        }
        for(int j=0;j<minsize;j++)
        {
            int flag=0;
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i][j]!=strs[0][j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
            else ret=ret+strs[0][j];
        } 
        return ret;
    }
};
// @lc code=end

