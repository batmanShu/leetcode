/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int countNum[26]={0};
        for(int i=0;i<s.size();i++)
        {
            countNum[s[i]-'a']++;
        }
        for(int j=0;j<t.size();j++)
        {
            if(countNum[t[j]-'a']==0)
            {
                return false;
            }
            else
            {
                countNum[t[j]-'a']--;
            }
            
        }
        return true;
    }
};
// @lc code=end

