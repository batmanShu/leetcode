class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int buy=prices[0];
        int sell=0;
        int maxProfit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-prices[i-1]>0)
            {
                if(prices[i]-buy>maxProfit) 
                {
                    sell=prices[i];
                    maxProfit=sell-buy;
                }
            }
            else
            {
                if(prices[i]<buy) buy=prices[i];
            }
        }
        return maxProfit;
    }
}; 
