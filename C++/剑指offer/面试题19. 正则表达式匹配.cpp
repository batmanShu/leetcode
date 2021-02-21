class Solution {
public:
    bool isMatch(string s, string p) {
        s=" "+s;
        p=" "+p;
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                {
                    if(s[i-1]!=p[j-2]&&p[j-2]!='.')
                    {
                        dp[i][j]=dp[i][j-2];
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-2]||dp[i][j-1]||dp[i-1][j];
                    }
                }
                if(s[i-1]==p[j-1]||p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
