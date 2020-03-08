class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(n==0) return 1;
        long long n_ll=n;
        if(n_ll<0)
        {
            x=1/x;
            n_ll=-n_ll;
        }
        double res=myPowCore(x,n_ll);
        return res;
    }
    double myPowCore(double x, long long n){
        double res=1;
        if(n==0) return res;
        if(n&1) res=res*x;
        n=n>>1;
        x=x*x;
        res=res*myPowCore(x,n);
        return res;
    }
};
