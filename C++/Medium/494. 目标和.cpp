class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S>1000) return 0;
        vector<int> dp(2001,0);
        dp[1000+nums[0]]=1;
        dp[1000-nums[0]]+=1;
        for(int i=1;i<nums.size();i++)
        {
            vector<int> next(2001,0);
            for(int j=0;j<2001;j++)
            {
                if(dp[j]>0)
                {
                    next[j+nums[i]]+=dp[j];
                    next[j-nums[i]]+=dp[j];
                }
            }
            dp=next;
        }
        return dp[1000+S]>0?dp[1000+S]:0;
    }
};
