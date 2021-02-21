class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size()-1].size(),INT_MAX);
        dp[0]=0;
        for(int i=0;i<triangle.size();i++)
        {
            for(int j=triangle[i].size()-1;j>=0;j--)
            {
                if(j==0)
                    dp[j]+=triangle[i][j];
                else
                    dp[j]=min(dp[j-1],dp[j])+triangle[i][j];
                
            }
        }
        int ret=INT_MAX;
        for(auto d:dp)
            ret=min(ret,d);
        return ret;
    }
};
