class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        vector<int> res;
        while(1)
        {
            int result=nums[left]+nums[right];
            if(result>target)
                right--;
            else if(result<target)
                left++;
            else
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
        }
        return res;
    }
};
