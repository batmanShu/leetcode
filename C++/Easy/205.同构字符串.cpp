/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        string temp;
        vector<int> indtemp;//字母的位置
        for(int i=0;i<s.length();i++)
        {
            if(i==0) 
            {
                temp=s[i];
                indtemp.push_back(i);
                continue;
            }
            for(int j=0;j<temp.length();j++)
            {
                if(s[i]==temp[j])
                {
                    if(t[i]==t[indtemp[j]])
                    {
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(t[i]==t[indtemp[j]])
                    {
                        return false;
                    }
                }
                
                if(j==temp.length()-1)
                {
                    temp+=s[i];
                    indtemp.push_back(i);
                }
            }
        }
        return true;
    }
};

