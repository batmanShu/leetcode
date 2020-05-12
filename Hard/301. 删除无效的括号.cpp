class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        str=s;
        mintodelete=mintodeletecore(s);
        stack<char> tmp;
        int rightleft=rightcount;
        dfs(0,0,"",tmp,rightleft);
        vector<string> vr;
        for(auto r:vec_res)
        {
            vr.push_back(r);
        }
        return vr;
    }
private:
    set<string> vec_res;
    string str;
    int rightcount=0;
    int mintodelete=0;
    int mintodeletecore(string s){
        stack<char> st;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')')
            {
                rightcount++;
                if(st.empty())
                    res++;
                else
                    st.pop();
            }
        }
        return res+st.size();
    }
    void dfs(int i, int count, string cur, stack<char> tmp,int rightleft){
        if(cur.size()>str.size()-mintodelete||tmp.size()>rightleft)
            return;
        if(i>=str.size())
        {
            if(tmp.empty())
                vec_res.insert(cur);
            return;
        }
        if(str[i]=='(')
        {
            if(count<mintodelete)
                dfs(i+1,count+1,cur,tmp,rightleft);
            tmp.push(str[i]);
            cur=cur+str[i];
            dfs(i+1,count,cur,tmp,rightleft);
        }
        else if(str[i]==')')
        {
            rightleft--;
            if(tmp.empty())
            {
                if(count<mintodelete)
                    dfs(i+1,count+1,cur,tmp,rightleft);
            }
            else
            {
                if(count<mintodelete)
                    dfs(i+1,count+1,cur,tmp,rightleft);
                tmp.pop();
                cur=cur+str[i];
                dfs(i+1,count,cur,tmp,rightleft);
            }
        }
        else
        {
            cur=cur+str[i];
            dfs(i+1,count,cur,tmp,rightleft);
        }
    }
};
