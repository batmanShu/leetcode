class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        if(n<1) return res;
        sort(nums.begin(),nums.end());
        //头部缺失的数字
        for(int i=1;i<nums[0];i++)
        {
            res.push_back(i);
        }
        //中间缺失的数字
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1||nums[i]==nums[i-1]) continue;
            for(int j=nums[i-1]+1;j<nums[i];j++)
            {
                res.push_back(j);
            }
        }
        //尾部缺失的数字
        for(int i=n;i>nums[n-1];i--)
        {
            res.push_back(i);
        }
        return res;
    }
};
