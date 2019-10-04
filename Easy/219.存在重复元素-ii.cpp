/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()==1) return false;
        map<int,int> dic;
        for(int i=0;i<nums.size();i++)
        {
            if(dic.count(nums[i])==0)
            {
                dic.insert(pair<int,int>(nums[i],i));
            }
            else
            {
                if(i-dic[nums[i]]<k+1)
                {
                    return true;
                } 
                else
                {
                    dic[nums[i]]=i;
                }
                
            }
            
        }
        return false;
    }
};
// @lc code=end

