/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int curhead=0;
        int curend=height.size()-1;
        int max_area=computeArea(height[curhead],height[curend],curend-curhead);
        int cur_area=0;
        while(curhead<curend)
        {
            if(height[curhead]<height[curend]) ++curhead;
            else --curend;
            cur_area=computeArea(height[curhead],height[curend],curend-curhead);
            max_area=max(max_area,cur_area);
        }
        return max_area;
    }
    int computeArea(int a, int b, int l){
        return min(a,b)*l;
    }
};
// @lc code=end

