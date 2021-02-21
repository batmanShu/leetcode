/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3) return ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            if(nums[i]>0) break;
            if(nums[k]<0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0) 
                {
                    ret.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j]==nums[++j]);
                    while(j<k&&nums[k]==nums[--k]);
                }
                else if(nums[i]+nums[j]+nums[k]>0) --k;
                else ++j;
            }
        }
        return ret;
    }
};
// @lc code=end

