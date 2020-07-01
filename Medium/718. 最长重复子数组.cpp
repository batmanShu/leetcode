class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lenA=A.size();
        int lenB=B.size();
        int res=0;
        vector<vector<int>> dp(lenA,vector<int>(lenB,0));
        for(int i=0;i<lenA;i++)
        {
            for(int j=0;j<lenB;j++)
            {
                if(A[i]==B[j])
                {
                    if(i>0&&j>0)
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};
