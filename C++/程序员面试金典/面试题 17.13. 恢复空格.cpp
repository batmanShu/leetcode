class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> dp(sentence.size()+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=sentence.size();i++)
        {
            for(auto s:dictionary)
            {
                int len=s.size();
                if(i>=len)
                {
                    if(s==sentence.substr(i-len,len))
                        dp[i]=min(dp[i],dp[i-len]);
                }
            }
            dp[i]=min(dp[i-1]+1,dp[i]);
        }
        return dp[sentence.size()];
    }
};
