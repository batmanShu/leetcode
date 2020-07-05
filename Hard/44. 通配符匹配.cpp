class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s=s.size();
        int len_p=p.size();
        vector<vector<bool>> dp(len_s+1,vector<bool>(len_p+1,false));
        dp[0][0]=true;
        for(int j=1;j<len_p+1;j++)
        {
            if(p[j-1]=='*')
            {
                dp[0][j]=dp[0][j-1];
            }
        }
        for(int i=1;i<len_s+1;i++)
        {
            for(int j=1;j<len_p+1;j++)
            {
                if(p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(s[i-1]==p[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(j>1&&p[j-2]=='*')
                    {
                        dp[i][j]=dp[i][j-1];
                        continue;
                    }
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1];;
                }
            }
        }
        return dp[len_s][len_p];
    }
};
