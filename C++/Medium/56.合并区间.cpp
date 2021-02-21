class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        if(intervals.size()==0) return res;
        int cur_head=intervals[0][0];
        int cur_tail=intervals[0][1];
        for(auto itr:intervals)
        {
            if(itr[0]<=cur_tail)
            {
                if(itr[1]<=cur_tail) continue;
                else cur_tail=itr[1];
            }
            else
            {
                vector<int> temp;
                temp.push_back(cur_head);
                temp.push_back(cur_tail);
                res.push_back(temp);
                cur_head=itr[0];
                cur_tail=itr[1];
            }
        }
        if(cur_tail==intervals[intervals.size()-1][1]&&cur_head==intervals[intervals.size()-1][0])
        {
            res.push_back(intervals[intervals.size()-1]);
        }
        else
        {
            vector<int> temp;
            temp.push_back(cur_head);
            temp.push_back(cur_tail);
            res.push_back(temp);
        }

        return res;
    }
};
