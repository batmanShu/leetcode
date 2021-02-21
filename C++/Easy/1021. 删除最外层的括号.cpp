class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> s;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(')
            {
                s.push(S[i]);
                if(s.size()==1)
                    S[i]='#';
            }
            else
            {
                s.pop();
                if(s.empty())
                    S[i]='#';
            }
        }
        for(auto itr=S.begin();itr!=S.end();)
        {
            if(*itr=='#')
                S.erase(itr);
            else
                itr++;
        }
        return S;
    }
};
