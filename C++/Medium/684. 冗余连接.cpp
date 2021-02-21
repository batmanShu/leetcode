class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        int id=0;
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            if(mp.find(a)!=mp.end()&&mp.find(b)!=mp.end())
            {
                if(mp[a]==mp[b])
                    ans=edges[i];
                else
                    setid(mp[b],mp[a],mp);
            }
            if(mp.find(a)==mp.end()&&mp.find(b)==mp.end())
            {
                mp[a]=id;
                mp[b]=id;
                id++;
            }
            if(mp.find(a)==mp.end())
            {
                mp[a]=mp[b];
            }
            if(mp.find(b)==mp.end())
            {
                mp[b]=mp[a];
            }
        }
        return ans;
    }
private:
    void setid(int b,int a,unordered_map<int,int>& mp) {
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second==b)
                itr->second=a;
        }
    }
};
