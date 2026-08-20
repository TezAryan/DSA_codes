class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<long long> dp(amount + 1, 0);

        dp[0] = 1;

        for(int coin : coins) {

            for(int i = coin; i <= amount; i++) {

                dp[i] = min(dp[i] + dp[i - coin],
                            (long long)INT_MAX);
            }
        }

        return dp[amount];
    }
};