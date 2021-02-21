/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size()==1)
        {
            if(nums[0]==0) return 1;
            else return 0;
        }
        sort(nums.begin(),nums.end());
        if(nums[0]!=0) return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=i) return i;
        }
        return nums.size();
    }
};
// @lc code=end

