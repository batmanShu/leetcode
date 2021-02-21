class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int left=0;
        int right=left+1;
        int temp=nums[left];
        int res=INT_MAX;
        while(left<right&&right<=nums.size())
        {
            int ans;
            while(temp>=s&&left<right)
            {
                ans=right-left;
                res=min(res,ans);
                temp-=nums[left];
                left++;
            }
            while(temp<s&&right<=nums.size())
            {
                if(right<nums.size())
                    temp+=nums[right];
                right++;
            }
        }
        return res==INT_MAX?0:res;
    }
};
