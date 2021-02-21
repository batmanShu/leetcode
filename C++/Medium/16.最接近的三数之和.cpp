/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ret=nums[0]+nums[1]+nums[nums.size()-1];
        int min_distance=abs(ret-target);
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                int distance=sum-target;
                if(distance==0) return sum;
                else if(distance<0) ++j;
                else --k;
                if(abs(distance)<min_distance)
                {
                    min_distance=abs(distance);
                    ret=sum;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

