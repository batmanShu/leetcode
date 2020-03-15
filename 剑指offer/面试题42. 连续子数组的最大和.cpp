class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int maxsum=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum>=0) 
                sum+=nums[i];
            else
                sum=nums[i];
            if(sum>maxsum)
                maxsum=sum;
        }
        return maxsum;
    }
};
