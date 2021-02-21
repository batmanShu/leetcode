class Solution {
public:
    int jump(vector<int>& nums) {
        int maxpos=0,step=0,end=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxpos=max(nums[i]+i,maxpos);
            if(i==end)
            {
                step++;
                end=maxpos;
            }
        }
        return step;
    }
};
