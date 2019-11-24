/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) return true;
        stack<char> s_char;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') s_char.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                    if(s_char.empty()||s_char.top()!='(') return false;
                    else s_char.pop();
                }
                else if(s[i]==']')
                {
                    if(s_char.empty()||s_char.top()!='[') return false;
                    else s_char.pop();
                }
                else if(s[i]=='}')
                {
                    if(s_char.empty()||s_char.top()!='{') return false;
                    else s_char.pop();
                }
            }
        }
        if(s_char.empty()) return true;
        return false;
    }
};
// @lc code=end

