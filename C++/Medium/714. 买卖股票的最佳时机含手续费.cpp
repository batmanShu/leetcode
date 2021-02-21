class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp0(prices.size(),0);
        vector<int> dp1(prices.size(),-prices[0]);
        for(int i=1;i<prices.size();i++)
        {
            dp0[i]=max(dp0[i-1],dp1[i-1]+prices[i]-fee);
            dp1[i]=max(dp1[i-1],dp0[i-1]-prices[i]);
        }
        return dp0[prices.size()-1];
    }
};
