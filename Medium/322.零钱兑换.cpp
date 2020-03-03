class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        auto dp = vector<int>(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto a = 1; a <= amount; ++a) {
            for (const auto & coin : coins) {
                if (a >= coin && dp[a - coin] < INT_MAX) {
                    dp[a] = min(dp[a], dp[a-coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
