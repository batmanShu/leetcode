class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        for(auto num:nums)
        {
            product*=num;
        }
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
            int subproduct=1;
            if(nums[i]==0)
            {
                for(int j=0;j<nums.size();j++)
                {
                    if(i==j) continue;
                    subproduct*=nums[j];
                }
            }
            else
            {
                subproduct=product/nums[i];
            }
            ret.push_back(subproduct);
        }
        return ret;
    }
};
