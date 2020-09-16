class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk;
        for(int i=0;i<s.size();i++)
        {
            if(stk.find(s[i])!=string::npos)
                continue;
            while(!stk.empty()&&s[i]<stk.back()&&s.find(stk.back(),i)!=string::npos)
            {
                stk.pop_back();
            }
            stk.push_back(s[i]);
        }
        return stk;
    }
};
