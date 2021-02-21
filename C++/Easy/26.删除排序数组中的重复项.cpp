/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto itr=nums.begin();itr!=nums.end();++itr)
        {
            int i=1;
            while(itr+i<nums.end()&&*itr==*(itr+i)) ++i;
            if(i==1) continue;
            else
            {
                nums.erase(itr+1,itr+i);
            }
        }
        return nums.size();
    }
};
// @lc code=end

