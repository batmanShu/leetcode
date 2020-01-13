class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i=i+2)
        {
            if(i+1>=nums.size()) break;
            if(nums[i]-nums[i+1]!=0) return nums[i];
        }
        return nums[nums.size()-1];
    }
};
