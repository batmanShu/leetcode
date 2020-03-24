class Solution {
public:
    int massage(vector<int>& nums) {
        int dp0=0,dp1=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=dp0;
            dp0=max(dp0,dp1);
            dp1=temp+nums[i];
        }
        return max(dp0,dp1);
    }
};
