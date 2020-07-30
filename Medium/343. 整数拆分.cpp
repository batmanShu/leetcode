class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        int ans=0;
        for(int i=1;i<n;i++)
        {
            ans=max(ans,core(i)*core(n-i));
        }
        return ans;
    }
private:
    unordered_map<int,int> mp;
    int core(int n) {
        int ans=n;
        if(mp.find(n)!=mp.end())
            return mp[n];
        for(int i=1;i<n;i++)
        {
            ans=max(ans,core(i)*core(n-i));
        }
        mp[n]=ans;
        return ans;
    }
};
