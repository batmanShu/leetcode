class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0||x==1) return 1;
        long long N=n;
        if(N<0)
        {
            x=1/x;
            N=-N;
        }
        double res=1;
        res=myPow(x,N/2);
        if(N%2==0)
        {
            res=res*res;
        }
        else
        {
            res=res*res*x;
        }
        return res;
    }
};
