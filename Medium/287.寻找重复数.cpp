class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) return -1;
        if(nums.size()==2) return nums[0];
        int fast=0;
        int slow=0;
        fast=nums[nums[fast]];
        slow=nums[slow];
        while(nums[slow]!=nums[fast])
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        int begin=0;
        while(nums[slow]!=nums[begin])
        {
            slow=nums[slow];
            begin=nums[begin];
        }
        return nums[slow];
    }
};
