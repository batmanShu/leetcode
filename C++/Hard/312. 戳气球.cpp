class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> memo1(nums.size(),vector<int>(nums.size(),0));;
        memo=memo1;
        return dp(nums,0,nums.size()-1);
    }
    int dp(vector<int> nums, int left, int right) {
        if(left>right) return 0;
        if(memo[left][right]>0) return memo[left][right];
        int ans=0;
        for(int i=left+1;i<right;i++)
        {
            ans=max(ans,nums[left]*nums[i]*nums[right]+dp(nums,left,i)+dp(nums,i,right));
        }
        memo[left][right]=ans;
        return ans;
    }
private:
    vector<vector<int>> memo;
};
