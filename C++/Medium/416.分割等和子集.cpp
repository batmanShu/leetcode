class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        int target=sum>>1;
        int N=nums.size();
        vector<vector<bool>> dp(N+1,vector<bool>(target+1,false));
        dp[0][0]=true;
        for(int i=1;i<N+1;i++)
        {
            dp[i]=dp[i-1];
            for(int j=target;j>=nums[i-1];j--)
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
            if(dp[i][target]) return true;
        }
        return false;
    }
};
