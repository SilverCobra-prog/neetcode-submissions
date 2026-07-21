class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (target < -sum || target > sum) return 0;

        vector<vector<int>> dp(2 * sum + 1, vector<int>(n + 1));
        int offset = sum;

        dp[offset][0] = 1;

        for (int j = 1; j <= n; j++) {
            for (int i = -sum; i <= sum; i++) {
                if (i - nums[j - 1] >= -sum) {
                    dp[i + offset][j] +=
                        dp[i - nums[j - 1] + offset][j - 1];
                }

                if (i + nums[j - 1] <= sum) {
                    dp[i + offset][j] +=
                        dp[i + nums[j - 1] + offset][j - 1];
                }
            }
        }

        return dp[target + offset][n];
    }
};