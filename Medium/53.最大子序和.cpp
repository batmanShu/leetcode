class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int prev=0;
        int temp=0;
        for(int i=0;i<nums.size();i++) 
        {
            temp=nums[i]+prev;
            if(temp<=0) 
            {
                if(nums[i]>maxsum) maxsum=nums[i];
                prev=0;
                continue;
            }
            if(temp>maxsum) maxsum=temp;
            prev=temp;
        }
        return maxsum;
    }
};
