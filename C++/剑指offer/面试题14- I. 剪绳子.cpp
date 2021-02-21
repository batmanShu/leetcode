class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int>  dp(n+1,1);
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<n+1;i++)
        {
            int temp=0;
            for(int j=i-1;j>0;j--)
            {
                temp=max(temp,dp[j]*dp[i-j]);
            }
            dp[i]=temp;
        }
        return dp[n];
    }
};
