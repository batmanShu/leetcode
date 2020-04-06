class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int dp[m+1][n+1];
        if(m*n==0) return m+n;
        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<n+1;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                int temp1=dp[i][j-1]+1;
                int temp2=dp[i-1][j]+1;
                int temp3=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1]) temp3++;
                dp[i][j]=min(temp1,min(temp2,temp3));
            }
        }
        return dp[m][n];
    }
};
