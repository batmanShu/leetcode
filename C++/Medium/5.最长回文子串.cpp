/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res="$#";
        for(int i=0;i<s.length();i++)
        {
            res+=s[i];
            res+="#";
        }
        int right=0;
        int mi=0;
        vector<int> P(res.length(),0);
        int maxLength=0;
        int maxPoint=0;
        for(int i=1;i<res.length();i++)
        {
            P[i]=right>i?min(P[2*mi-i],right-i):1;
            while (res[i+P[i]]==res[i-P[i]])
            {
                P[i]++;
            }
            if(right<P[i]+i)
            {
                right=P[i]+i;
                mi=i;
            }
            if(P[i]>maxLength)
            {
                maxLength=P[i];
                maxPoint=i;
            }
            
        }
        return s.substr((maxPoint-maxLength)/2,maxLength-1);
    }
};
// @lc code=end

