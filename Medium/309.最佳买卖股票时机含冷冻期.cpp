class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days=prices.size();
        if(days<2) return 0;
        int dp_0=0;
        int dp_1=INT_MIN;
        int pre_0=0;
        for(int i=0;i<days;i++)
        {
            int temp=dp_0;
            dp_0=max(dp_0,dp_1+prices[i]);
            dp_1=max(dp_1,pre_0-prices[i]);
            pre_0=temp;
        }
        return dp_0;
    }
};
