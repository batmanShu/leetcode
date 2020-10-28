class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int> record;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(record.count(itr->second))
                return false;
            record.insert(itr->second);
        }
        return true;
    }
};
