class Solution {
public:
    int numWays(int n) {
        vector<int> dp(n+1,1);
        for(int i=2;i<n+1;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];
    }
};
