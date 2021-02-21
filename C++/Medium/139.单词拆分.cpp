class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        for(int i=0;i<s.size()+1;i++)
        {
            for(auto word:wordDict)
            {
                int wl=word.size();
                if(i>=wl)
                {
                    int cur=s.compare(i-wl,wl,word);
                    if(cur==0&&dp[i-wl]==1) dp[i]=1;
                }
            }
        }
        return dp[s.size()];
    }
};
