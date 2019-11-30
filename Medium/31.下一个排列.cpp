/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int k=nums.size()-1;k>-1;k--)
        {
            for(int i=nums.size()-1;i>k;i--)
            {
                if(nums[k]<nums[i])
                {
                    swap(nums[k],nums[i]);
                    sort(nums.begin()+k+1,nums.end());
                    return;
                }
            }
        }
        for(int m=0;m<nums.size()/2;m++)
        {
            swap(nums[m],nums[nums.size()-1-m]);
        }
    }
};
// @lc code=end

