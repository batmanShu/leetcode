class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        for(int i=candidates.size()-1;i>-1;i--)
        {
            if(target<candidates[i]) continue;
            int next_target=target-candidates[i];
            if(next_target>0)
            {
                auto itr_cut=candidates.begin()+i+1;
                vector<int> next_candidates(candidates.begin(),itr_cut);
                vector<vector<int>> prev_ret=combinationSum(next_candidates,next_target);
                for(auto itr=prev_ret.begin();itr!=prev_ret.end();itr++)
                {
                    itr->push_back(candidates[i]);
                    ret.push_back(*itr);
                }
            }
            else
            {
                vector<int> temp;
                temp.push_back(candidates[i]);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};