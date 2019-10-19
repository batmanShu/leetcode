/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> p_w;
        unordered_map<string,int> w_c;
        vector<string> words;
        int pos=0;
        int i=0;
        while(pos!=-1)
        {
            pos=str.find_first_of(' ',i);
            string temp=str.substr(i,pos-i);
            words.push_back(temp);
            i=pos+1;
        }
        if(words.size()!=pattern.size()) return false;
        for(int j=0;j<words.size();j++)
        {
            if(w_c.count(words[j])==0)//单词没出现过
            {
                if(p_w.count(pattern[j])!=0) return false;//pattern是否是新pattern
                p_w[pattern[j]]=words[j];
                w_c[words[j]]=1;
            }
            else //单词出现过
            {
                if(p_w[pattern[j]]!=words[j]) return false;
                else w_c[words[j]]++;
            }
            
        }
        return true;
    }
};
// @lc code=end

