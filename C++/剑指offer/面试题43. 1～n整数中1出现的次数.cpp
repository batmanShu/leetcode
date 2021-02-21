class Solution {
public:
    int countDigitOne(int n) {
        long long cur,high,digit,low;
        int count=0;
        digit=0;
        high=n/10;
        cur=n%10;
        low=0;
        while(low!=n)
        {
            if(cur>1)
            {
                count+=(high+1)*pow(10,digit);
            }
            else if(cur==1)
            {
                count+=high*pow(10,digit)+low+1;
            }
            else
            {
                count+=high*pow(10,digit);
            }
            digit++;
            long long temp=pow(10,digit+1);
            high=n/temp;
            low=n%(temp/10);
            cur=(n%temp)/(temp/10);
        }
        return count;
    }
};
