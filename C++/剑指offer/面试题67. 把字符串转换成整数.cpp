class Solution {
public:
    int strToInt(string str) {
        if(str.size()==0) return 0;
        long long res=0;
        int i;
        int flag=1;
        for(i=0;i<str.size();)
        {
            if(str[i]!='+'&&str[i]!='-'&&(str[i]<'0'||str[i]>'9'))
            {
                if(str[i]!=' ') return 0;
                i++;
            }
            else break;
        }
        cout<<i<<endl;
        if(str[i]=='-') 
        {
            flag=-1;
            i++;
        }
        else if(str[i]=='+')
        {
            i++;
        }
        for(int j=i;j<str.size();j++)
        {
            if(str[j]>='0'&&str[j]<='9')
            {
                if(res>INT_MAX) 
                {
                    if(flag==1) return INT_MAX;
                    if(flag==-1) return INT_MIN;
                }
                res=res*10+str[j]-'0';
            }
            else
            {
                break;
            }
        }
        res=flag*res;
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return res;
    }
};
