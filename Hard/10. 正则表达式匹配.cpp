class Solution {
public:
    bool isMatch(string s, string p) {
        s=" "+s;
        p=" "+p;
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<p.size();j++)
            {
                if(p[j]!='*')
                {
                    if(p[j]=='.'||p[j]==s[i])
                    {
                        dp[i+1][j+1]=dp[i][j];
                    }
                }
                else
                {
                    if(i>0&&(s[i]==p[j-1]||p[j-1]=='.')) dp[i+1][j+1]=dp[i][j+1]||dp[i][j-1]||dp[i+1][j-1];
                    else
                    {
                        dp[i+1][j+1]=dp[i+1][j-1];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
