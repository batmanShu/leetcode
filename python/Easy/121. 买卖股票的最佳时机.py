class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        curP = 0
        for i in range(1,len(prices)):
            temp = prices[i] - prices[i-1]
            if curP + temp > 0:
                curP = curP + temp
            else:
                curP = 0
            maxP = max(curP, maxP)
        return maxP
