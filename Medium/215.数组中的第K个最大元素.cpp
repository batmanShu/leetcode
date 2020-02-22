class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0) return -1;
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
