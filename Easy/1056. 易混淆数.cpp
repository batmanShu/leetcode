class Solution {
public:
    bool confusingNumber(int N) {
        bool flag=false;
        string s="";
        while(N!=0)
        {
            int bit=N%10;
            s=s+to_string(bit);
            N=N/10;
        }
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(i==j)
                if(s[i]=='6'||s[i]=='9')
                    flag=true;
            if(s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='7'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='7')
                return false;
            else if(!(s[i]==s[j]||(s[i]=='6'&&s[j]=='9')||(s[i]=='9'&&s[j]=='6')))
                flag=true;
            i++;
            j--;
        }
        return flag;
    }
};
