class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for(auto itr:mp)
        {
            pq.push(make_pair(itr.second,itr.first));
        }
        vector<int> ret;
        for(int i=0;i<k;i++)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
