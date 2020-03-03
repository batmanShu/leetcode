class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size()<2) return -1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i]) return nums[i];
        }
        return -1;
    }
};
