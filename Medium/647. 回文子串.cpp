class Solution {
public:
    int countSubstrings(string s) {
        string s_p=preprocess(s);
        vector<int> p(s_p.size(),0);
        int c=0,R=0;
        for(int i=1;i<s_p.size();i++)
        {
            int r=0;
            if(i<R)
            {
                r=p[2*c-i];
                if(i+r<R) p[i]=r;
                else
                {
                    r=R-i;
                    while(i+r+1<s_p.size()&&i-r-1>=0)
                    {
                        if(s_p[i+r+1]==s_p[i-r-1]) r++;
                        else break;
                    }
                    p[i]=r;
                }
            }
            else
            {
                while(i+r+1<s_p.size()&&i-r-1>=0)
                {
                    if(s_p[i+r+1]==s_p[i-r-1]) r++;
                    else break;
                } 
                p[i]=r;
            }
            if(i+r>R)
            {
                c=i;
                R=c+r;
            }
        }
        int res=0;
        for(int i=0;i<s_p.size();i++)
        {
            cout<<p[i]<<endl;
            if(p[i]==1) res++;
            if(p[i]>1&&s_p[i]=='#') res+=p[i]/2;
            if(p[i]>1&&s_p[i]!='#') res+=(p[i]-1)/2+1;
        }
        return res;
    }
    string preprocess(string s) {
        string res="^";
        for(int i=0;i<s.size();i++)
        {
            res=res+"#"+s[i];
        }
        res=res+"#*";
        return res;
    }
};
