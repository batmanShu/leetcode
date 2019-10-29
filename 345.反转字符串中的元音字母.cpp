/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> indvowel;
        for(int i=0;i<s.size();i++)
        {
            if(isvowel(s[i]))
            {
                indvowel.push_back(i);
            }
        }
        for(int i=0;i<indvowel.size()/2;i++)
        {
            swap(s[indvowel[i]],s[indvowel[indvowel.size()-1-i]]);
        }
        return s;
    }
    bool isvowel(char temp)
    {
        if(temp=='a'||temp=='e'||temp=='i'||temp=='o'||temp=='u'||temp=='A'||temp=='E'||temp=='I'||temp=='O'||temp=='U') return true;
        else return false;
    }
};
// @lc code=end

