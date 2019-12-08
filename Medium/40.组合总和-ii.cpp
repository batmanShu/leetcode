class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        for(int i=candidates.size()-1;i>-1;i--)
        {
            if(candidates[i]>target) continue;
            int next_target=target-candidates[i];
            if(next_target==0)
            {
                vector<int> temp;
                temp.push_back(candidates[i]);
                ret.push_back(temp);
            }
            else
            {
                auto itr_end=candidates.begin()+i;
                vector<int> next_candidates(candidates.begin(),itr_end);
                vector prev_ret=combinationSum2(next_candidates,next_target);
                for(auto itr=prev_ret.begin();itr!=prev_ret.end();itr++)
                {
                    itr->push_back(candidates[i]);
                    ret.push_back(*itr);
                }
            }
        }
        set<vector<int>> ret_set;
        for(auto itr=ret.begin();itr!=ret.end();itr++)
        {
            ret_set.insert(*itr);
        }
        vector<vector<int>> ret_new;
        for(auto itr=ret_set.begin();itr!=ret_set.end();itr++)
        {
            ret_new.push_back(*itr);
        }
        return ret_new;
    }
};