class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int c=0;
        string ans;
        while(i>=0&&j>=0)
        {
            if(c==0)
            {
                if(a[i]=='1'&&b[j]=='1')
                {
                    c=1;
                    ans='0'+ans;
                }
                else if(a[i]=='0'&&b[j]=='0')
                {
                    ans='0'+ans;
                }
                else
                {
                    ans='1'+ans;
                }
            }
            else
            {
                if(a[i]=='1'&&b[j]=='1')
                {
                    c=1;
                    ans='1'+ans;
                }
                else if(a[i]=='0'&&b[j]=='0')
                {
                    c=0;
                    ans='1'+ans;
                }
                else
                {
                    c=1;
                    ans='0'+ans;
                }
            }
            i--;
            j--;
        }
        while(i>=0)
        {
            if(c==0)
            {
                ans=a[i]+ans;
            }
            else
            {
                if(a[i]=='1')
                {
                    c=1;
                    ans='0'+ans;
                }
                else
                {
                    c=0;
                    ans='1'+ans;
                }
            }
            i--;
        }
        while(j>=0)
        {
            if(c==0)
            {
                ans=b[j]+ans;
            }
            else
            {
                if(b[j]=='1')
                {
                    c=1;
                    ans='0'+ans;
                }
                else
                {
                    c=0;
                    ans='1'+ans;
                }
            }
            j--;
        }
        if(c==1)
        {
            ans='1'+ans;
        }
        return ans;
    }
};
