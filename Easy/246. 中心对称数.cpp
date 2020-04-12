class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i=0;
        int j=num.length()-1;
        while(i<=j)
        {
            if(num[i]=='1')
            {
                if(num[j]!='1') 
                    return false;
            }
            else if(num[i]=='6')
            {
                if(num[j]!='9') 
                    return false;
            }
            else if(num[i]=='8')
            {
                if(num[j]!='8')
                    return false;
            }
            else if(num[i]=='9')
            {
                if(num[j]!='6')
                    return false;
            }
            else if(num[i]=='0')
            {
                if(num[j]!='0')
                    return false;
            }
            else
                return false;
            i++;
            j--;
        }
        return true;
    }
};
