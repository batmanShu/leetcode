class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums[0]==1) return 0;
        vector<int> copynums=nums;
        for(int i=0;i<nums.size();i++)
        {
            copynums[nums[i]%nums.size()]+=nums.size()+1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(copynums[i]<=nums.size())
                return i;
        }
        return nums.size();
    }
};
