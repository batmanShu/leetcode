class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(auto& num:nums)
        {
            if(num<=0)
                num=n+1;
        }
        for(auto num:nums)
        {
            num=abs(num);
            if(num<=n)
            {
                nums[num-1]=-abs(nums[num-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1; 
        }
        return n+1;
    }
};
