class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        for(int i=0,j=nums.size()-1;i<j;i++)
        {
            if(!(nums[i]&1))
            {
                while(j>i&&!(nums[j]&1)) j--;
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
};
