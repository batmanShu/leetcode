class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int res=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==res) count++;
            else
            {
                count--;
            }
            if(count<0) 
            {
                res=nums[i];
                count=1;
            }
        }
        return res;
    }
};
