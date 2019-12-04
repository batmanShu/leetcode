/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        if(target<nums[left]) return 0;
        if(target>nums[right]) return nums.size();
        while(left<= right)
        {
            mid=(left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target<nums[mid])
            {
                right=mid;
            }
            else
            {
                left=mid;
            }
            if(right-left==1) 
            {
                if(nums[left]==target) return left;
                if(nums[right]==target) return right;
                return right;
            }
        }
        return -1;
    }
};
// @lc code=end

