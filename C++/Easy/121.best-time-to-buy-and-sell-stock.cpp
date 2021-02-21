/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        if(prices.size()<2) return result;
        int i=0;
        int profit=0;
        for (int j=i+1;j<prices.size();j++)
        {
            profit=prices[j]-prices[i];
            if(profit<=0) i=j;
            if(profit>result)
            {
                result=profit;
            }
        }
        return result;
    }
};

