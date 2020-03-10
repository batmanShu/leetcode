class Solution {
public:
    bool isNumber(string s) {
       int i=s.find_first_not_of(' ');
       if(i==string::npos) return false;
       int j=s.find_last_not_of(' ');
       s=s.substr(i,j-i+1);
       int e=s.find('e');
       if(e==string::npos) e=s.find('E');
       if(e==string::npos) return judgeP(s);
       return judgeP(s.substr(0,e))&&judgeS(s.substr(e+1));
    }
    bool judgeP(string s){
        bool res=false;
        bool commaflag=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+'||s[i]=='-')
            {
                if(i!=0) return false;
            }
            else if(s[i]=='.')
            {
                if(commaflag) return false;
                commaflag=true;          
            }
            else if(s[i]<'0'||s[i]>'9')
            {
                return false;
            }
            else
            {
                res=true;
            }
        }
        return res;
    }
    bool judgeS(string s){
        bool res=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+'||s[i]=='-')
            {
                if(i!=0) return false;
            }
            else if(s[i]=='.')
            {
                return false;         
            }
            else if(s[i]<'0'||s[i]>'9')
            {
                return false;
            }
            else
            {
                res=true;
            }
        }
        return res;
    }
};
