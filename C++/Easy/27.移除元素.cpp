/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                count++;
                int j=1;
                while(i+j<nums.size()&&nums[i+j]!=val) 
                {
                    nums[i+j-count]=nums[i+j];
                    j++;
                }
            }
        }
        return nums.size()-count;
    }
};
// @lc code=end

