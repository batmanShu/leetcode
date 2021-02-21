class Solution {
public:
    int cuttingRope(int n) {
        long long ans=1;
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        int b=0;
        while(n-3*b>4) b++;
        ans=pow(3,b)*(n-3*b)%1000000007;
        return ans;
    }
    long long pow(long long a, long long b){
        long long ans=1;
        while(b)
        {
            if(b&1) ans=(ans*a)%1000000007;
            b=b>>1;
            a=(a*a)%1000000007;
        }
        return ans;
    }
};
