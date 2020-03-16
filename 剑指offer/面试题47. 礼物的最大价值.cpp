class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int h=grid.size();
        if(h==0) return -1;
        int w=grid[0].size();
        vector<int> dp(w+1,0);
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                dp[j+1]=max(dp[j],dp[j+1])+grid[i][j];
            }
        }
        return dp[w];
    }
};
