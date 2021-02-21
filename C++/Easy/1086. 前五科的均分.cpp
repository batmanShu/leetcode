class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int,priority_queue<int>> mp;
        for(int i=0;i<items.size();i++)
        {
            mp[items[i][0]].push(items[i][1]);
        }
        vector<vector<int>> vec_res;
        for(auto m:mp)
        {
            vector<int> res;
            res.push_back(m.first);
            int avg=0;
            for(int i=0;i<5;i++)
            {
                avg+=m.second.top();
                m.second.pop();
            }
            avg=avg/5;
            res.push_back(avg);
            vec_res.push_back(res);
        }
        sort(vec_res.begin(),vec_res.end());
        return vec_res;
    }
};
