class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        days.push_back(366);
        vector<int> dp(367,INT_MAX);
        dp[366]=0;
        for(int i=days.size()-1;i>=0;i--)
        {
            for(int j=i+1;j<days.size();j++)
            {
                if(days[j]-days[i]>=1)
                {
                    dp[days[i]]=min(costs[0]+dp[days[j]],dp[days[i]]);
                    break;
                }
            }
            for(int j=i+1;j<days.size();j++)
            {
                if(days[j]-days[i]>=7)
                {
                    dp[days[i]]=min(costs[1]+dp[days[j]],dp[days[i]]);
                    break;
                }
            }
            for(int j=i+1;j<days.size();j++)
            {
                if(days[j]-days[i]>=30)
                {
                    dp[days[i]]=min(costs[2]+dp[days[j]],dp[days[i]]);
                    break;
                }
            }
        }
        return dp[days[0]];
    }
};
