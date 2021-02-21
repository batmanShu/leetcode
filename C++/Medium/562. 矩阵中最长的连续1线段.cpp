class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.size()==0)
            return 0;
        int len_row=M.size();
        int len_col=M[0].size();
        vector<vector<vector<int>>> dp(4,vector<vector<int>>(len_row,vector<int>(len_col,0)));
        int res=0;
        for(int i=0;i<len_row;i++)
        {
            for(int j=0;j<len_col;j++)
            {
                if(M[i][j]==1)
                {
                    if(j==0)
                        dp[0][i][j]=1;
                    else
                        dp[0][i][j]=dp[0][i][j-1]+1;
                    res=max(res,dp[0][i][j]);
                    if(i==0)
                        dp[1][i][j]=1;
                    else
                        dp[1][i][j]=dp[1][i-1][j]+1;
                    res=max(res,dp[1][i][j]);
                    if(i==0||j==0)
                        dp[2][i][j]=1;
                    else
                        dp[2][i][j]=dp[2][i-1][j-1]+1;
                    res=max(res,dp[2][i][j]);
                    if(i==0||j==len_col-1)
                        dp[3][i][j]=1;
                    else
                        dp[3][i][j]=dp[3][i-1][j+1]+1;
                    res=max(res,dp[3][i][j]);
                }
            }
        }
        return res;
    }
};
