class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return n;
        int p2=1,p3=1,p5=1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            if(dp[i]==dp[p2]*2) p2++;
            if(dp[i]==dp[p3]*3) p3++;
            if(dp[i]==dp[p5]*5) p5++;
        }
        return dp[n];
    }
};
