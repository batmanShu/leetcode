/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //思路：找函数的上升区间

        int result=0;
        for(int i=0;i<prices.size();i++)
        {
            if(i==0) 
            {
                continue;
            }
            else if(i==prices.size()-1)
            {
                if(prices[i]>prices[i-1])
                {
                    result=result+prices[i]-prices[i-1];
                }
            }
            else
            {
                if(prices[i]>prices[i-1])
                {
                    result=result+prices[i]-prices[i-1];
                }
            }
        }
        return result;
    }
};

