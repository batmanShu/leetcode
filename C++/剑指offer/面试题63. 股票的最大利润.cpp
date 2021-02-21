class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int profit=0;
        int maxProfit=0;
        int max=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--)
        {
            profit=max-prices[i];
            if(profit<0) max=prices[i];
            else
            {
                if(profit>maxProfit)
                    maxProfit=profit;
            }
        }
        return maxProfit;
    }
};
