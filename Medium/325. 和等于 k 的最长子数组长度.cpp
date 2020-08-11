class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int sum=0;
        mp[0].push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mp[sum].push_back(i+1);
        }
        int ans=0;
        for(auto m:mp)
        {
            int temp=k+m.first;
            if(mp.find(temp)!=mp.end())
            {
                for(int i=0;i<mp[temp].size();i++)
                {
                    for(int j=0;j<m.second.size();j++)
                    {
                        if(m.second[j]<mp[temp][i])
                            ans=max(ans,mp[temp][i]-m.second[j]);
                    }
                }
            }
        }
        return ans;
    }
};
