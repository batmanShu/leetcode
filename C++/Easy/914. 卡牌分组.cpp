class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(auto i:deck) mp[i]++;
        int g=-1;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(g<0) g=itr->second;
            else
                g=gcd(g,itr->second);
        }
        return g>=2?true:false;
    }
};
