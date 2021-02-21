class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto num:nums)
        {
            mp[num]++;
            if(mp[num-1]!=0)
                ans=max(ans,mp[num]+mp[num-1]);
            if(mp[num+1]!=0)
                ans=max(ans,mp[num]+mp[num+1]);
        }
        return ans;
    }
};
