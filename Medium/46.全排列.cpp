class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()==1)
        {
            vector<int> temp;
            temp.push_back(nums[0]);
            ret.push_back(temp);
            return ret;
        }
        for(auto itr=nums.begin();itr!=nums.end();itr++)
        {
            vector<vector<int>> prev_ret;
            if(itr==nums.begin())
            {
                vector<int> temp1(nums.begin()+1,nums.end());
                prev_ret=permute(temp1);
            }
            else if(itr==nums.end()-1)
            {
                vector<int> temp1(nums.begin(),nums.end()-1);
                prev_ret=permute(temp1);
            }
            else
            {
                vector<int> temp1(nums.begin(),itr);
                vector<int> temp2(itr+1,nums.end());
                temp1.insert(temp1.end(),temp2.begin(),temp2.end());
                prev_ret=permute(temp1);
            }
            for(auto itr2=prev_ret.begin();itr2!=prev_ret.end();itr2++)
            {
                itr2->push_back(*itr);
                ret.push_back(*itr2);
            }
        }
        return ret;
    }
};
