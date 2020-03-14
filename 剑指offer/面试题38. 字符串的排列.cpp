class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        dfs(s,0,res);
        return res;
    }
    void dfs(string s, int pos, vector<string>& res) {
        if(pos>=s.size()-1)
        {
            res.push_back(s);
            return;
        }
        for(int i=pos;i<s.size();i++)
        {
            if(judge(s,pos,i)) continue;
            swap(s[i],s[pos]);
            dfs(s,pos+1,res);
            swap(s[i],s[pos]);
        }
    }
    bool judge(string s, int start, int end) {
        for(int i=start;i<end;i++)
        {
            if(s[i]==s[end]) return true;
        }
        return false;
    }
};
