class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res_set;
        vector<vector<int>> res;
        backtrack(nums,res_set,0);
        for(auto itr=res_set.begin();itr!=res_set.end();itr++)
        {
            res.push_back(*itr);
        }
        return res;
    }
    void backtrack(vector<int>& nums,set<vector<int>>& res,int i)
    {
        if(i==nums.size()-1)
        {
            res.insert(nums);
        }
        else
        {
            for(int j=i;j<nums.size();j++)
            {
                swap(nums[i],nums[j]);
                backtrack(nums,res,i+1);
                swap(nums[i],nums[j]);
            }
        }
    }
};
