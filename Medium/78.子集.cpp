class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums,0,temp,res);
        return res;
    }
    void helper(vector<int>& nums,int level,vector<int>& temp,vector<vector<int>>& res){
        if(level==nums.size())
        {
            res.push_back(temp);
        }
        else
        {
            for(int i=0;i<2;i++)
            {
                if(i==0)
                {
                    temp.push_back(nums[level]);
                    helper(nums,level+1,temp,res);
                    temp.pop_back();
                }
                else
                {
                    helper(nums,level+1,temp,res);
                }
            }
        }
    }
};
