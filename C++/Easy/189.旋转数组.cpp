/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums1;
        vector<int> nums2;
        int length=nums.size();
        k=k%length;
        auto itr=nums.begin();
        itr=itr+nums.size()-k;
        nums1.assign(itr,nums.end());
        nums2.assign(nums.begin(),itr);
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        nums.assign(nums1.begin(),nums1.end());
    }
};

