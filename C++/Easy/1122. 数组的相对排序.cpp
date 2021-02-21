class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<arr1.size();i++)
        {
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++)
        {
            if(mp.find(arr2[i])!=mp.end())
            {
                for(int j=0;j<mp[arr2[i]];j++)
                {
                    ans.push_back(arr2[i]);
                }
                mp[arr2[i]]=0;
            }
        }
        vector<int> left_nums;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second!=0)
            {
                for(int i=0;i<itr->second;i++)
                {
                    left_nums.push_back(itr->first);
                }
            }
        }
        sort(left_nums.begin(),left_nums.end());
        ans.insert(ans.end(),left_nums.begin(),left_nums.end());
        return ans;
    }
};
