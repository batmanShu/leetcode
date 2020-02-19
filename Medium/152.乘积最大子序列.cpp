class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int imax=1;
        int imin=1;
        int max_result=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                int temp=imin;
                imin=imax;
                imax=temp;
            }
            imax=max(imax*nums[i],nums[i]);
            imin=min(imin*nums[i],nums[i]);
            max_result=max(max_result,imax);
        }
        return max_result;
    }
};
