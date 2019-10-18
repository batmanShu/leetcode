/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                int j=i+k;
                if(j>nums.size()-1) break;
                while(j<=nums.size()-1&&nums[j]==0)
                {
                    j++;
                }
                if(j>nums.size()-1) break;
                swap(nums[i],nums[j]);
                k=j-i;
                if(j==nums.size()-1) break;                 
            }
        }
    }
};
// @lc code=end

