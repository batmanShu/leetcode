/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size()<4) return ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;)
        {
            int temp_target=target-nums[i];
            for(int j=i+1;j<nums.size()-2;++j)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=nums.size()-1;
                while(k<l)
                {
                    int sum=nums[j]+nums[k]+nums[l];
                    if(sum<temp_target) ++k;
                    else if(sum>temp_target) --l;
                    else
                    {
                        ret.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l&&nums[k]==nums[++k]);
                        while(k<l&&nums[l]==nums[--l]);
                    }
                    
                }
            }
            while(i<nums.size()-3&&nums[i]==nums[++i]);
        }
        return ret;
    }
};
// @lc code=end

