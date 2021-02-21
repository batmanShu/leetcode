class Solution {
public:
    string decodeString(string s) {
        int len=s.size();
        if(len<1) return "";
        stack<pair<int,string>> st;
        string res="",ret="";
        int times=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]<='9'&&s[i]>='0') times=times*10+(s[i]-'0');
            else if(s[i]=='[')
            {
                st.push(make_pair(times,res));
                res="";
                times=0;
            }
            else if(s[i]==']')
            {
                times=st.top().first;
                string temp=res;
                while(times>=2)
                {
                    res=res+temp;
                    times--;
                }
                res=st.top().second+res;
                st.pop();
                if(st.empty()) 
                {
                    ret+=res;
                    res="";
                }
                times=0;
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return ret+res;
    }
};
