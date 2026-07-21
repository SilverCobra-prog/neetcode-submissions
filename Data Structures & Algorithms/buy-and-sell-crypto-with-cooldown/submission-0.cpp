class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        vector<int> maxTil(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int previousProfit = 0;
                if (j >= 2) {
                    previousProfit = maxTil[j - 2];
                }

                dp[i] = max(dp[i], previousProfit + prices[i] - prices[j]);
                maxTil[i] = dp[i];
                if (i > 0) {
                    maxTil[i] = max(maxTil[i], maxTil[i - 1]);
                }
            }
        }
        return maxTil[n-1];
    }
};
