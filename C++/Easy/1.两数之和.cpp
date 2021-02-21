/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums_order=nums;
        sort(nums_order.begin(),nums_order.end());
        int i=0,j=nums_order.size()-1;
        while(i<=j)
        {
            int sum=nums_order[i]+nums_order[j];
            if(sum>target)
            {
                j--;
            }
            else if(sum<target)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        vector<int> ind;
        for (int k=0;k<nums.size();k++)
        {
            if(nums[k]==nums_order[i])
            {
                ind.push_back(k);
            }
            else if(nums[k]==nums_order[j])
            {
                ind.push_back(k);
            }
            else continue;
        }
        return ind;
    }
};
// @lc code=end

