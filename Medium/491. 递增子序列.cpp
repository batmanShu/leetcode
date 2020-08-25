class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int l=ans.size();
            for(int j=0;j<l;j++)
            {
                if(nums[i]>=ans[j][ans[j].size()-1])
                {
                    vector<int> temp=ans[j];
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                }
            }
            vector<int> temp;
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
        set<vector<int>> s;
        for(auto itr=ans.begin();itr!=ans.end();)
        {
            if((*itr).size()<2)
                ans.erase(itr);
            else
            {
                s.insert(*itr);
                itr++;
            }
                
        }
        vector<vector<int>> res;
        for(auto vec:s)
            res.push_back(vec);
        return res;
    }
private:
    vector<vector<int>> ans;
};
