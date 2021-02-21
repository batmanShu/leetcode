/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string longestsubstring;
        string substring;
        for(int i=0;i<s.size();i++)
        {
            if(i==0) 
            {
                substring=s[i];
                longestsubstring=substring;
                continue;
            }
            if(s[i]==s[i-1])
            {
                if(substring.size()>longestsubstring.size()) longestsubstring=substring;
                substring=s[i];
                continue;
            }
            int flag=0; 
            int j=0;
            for(;j<substring.size()-1;j++)
            {
                if(s[i]==substring[j]) 
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                substring=substring+s[i];
                substring.erase(0,j+1);
            }
            else
            {
                substring=substring+s[i];
            }
            cout<<substring<<endl;
            if(substring.size()>longestsubstring.size()) longestsubstring=substring;
        }
        return longestsubstring.size();
    }
};
// @lc code=end

