/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> result;
        int j=0;
        for(int i=0;i<nums1.size();i++)
        {
            for(;j<nums2.size();j++)
            {
                if(nums1[i]<nums2[j])
                {
                    break;
                }
                if(nums1[i]==nums2[j])
                {
                    result.push_back(nums1[i]);
                    j++;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

