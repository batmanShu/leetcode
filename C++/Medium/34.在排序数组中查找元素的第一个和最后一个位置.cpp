/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        int flag=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]==target)
            {
                flag=1;
                break;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        int head=mid;
        int tail=mid;
        if(flag==1)
        {
            while(head>=0&&nums[head]==target)
            {
                head--;
            }
            while(tail<nums.size()&&nums[tail]==target)
            {
                tail++;
            }
        }
        else
        {
            head=-2;
            tail=0;
        }
        
        vector<int> ret;
        ret.push_back(head+1);
        ret.push_back(tail-1);
        return ret;
    }
};
// @lc code=end

