class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0) return 0;
        int dp[3]={costs[0][0],costs[0][1],costs[0][2]};
        for(int i=1;i<costs.size();i++)
        {
            int temp0=dp[0],temp1=dp[1],temp2=dp[2];
            dp[0]=min(temp1,temp2)+costs[i][0];
            dp[1]=min(temp0,temp2)+costs[i][1];
            dp[2]=min(temp0,temp1)+costs[i][2];
        }
        return min(dp[0],min(dp[1],dp[2]));
    }
};
