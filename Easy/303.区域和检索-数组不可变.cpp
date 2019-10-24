/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        for(auto i:nums)
        {
            if(sums.empty()) sums.push_back(i);
            else sums.push_back(sums.back()+i);
        }
    }
    
    int sumRange(int i, int j) {
        if(i>=1) return (sums[j]-sums[i-1]);
        else return sums[j];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

