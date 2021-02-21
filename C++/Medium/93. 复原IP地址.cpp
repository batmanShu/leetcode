class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        ans="";
        core(s,0,4);
        return vec_ans;
    }
private:
    void core(string& s,int ind,int spaceleft) {
        if(spaceleft==0&&ind==s.size())
        {
            ans.erase(0,1);
            vec_ans.push_back(ans);
            return;
        }
        if(s.size()-ind>spaceleft*3||spaceleft==0)
            return;
        ans=ans+".";
        for(int i=1;i<4&&ind+i<=s.size();i++)
        {

            string temp=s.substr(ind,i);
            string backup=ans;
            if(!isaddrvalid(temp))
                return;
            ans=ans+temp;
            core(s,ind+i,spaceleft-1);
            ans=backup;
        }
    }

    bool isaddrvalid(string s) {
        if(s[0]=='0')
            if(s.size()>1)
                return false;
        int temp=stoi(s);
        if(temp>255)
            return false;
        return true;
    }

    string ans;
    vector<string> vec_ans;

};
