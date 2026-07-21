class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& dp,
            vector<vector<int>>& matrix) {
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int best = 1;

        if (i > 0 && matrix[i - 1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(i - 1, j, dp, matrix));
        }

        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(i + 1, j, dp, matrix));
        }

        if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
            best = max(best, 1 + dfs(i, j - 1, dp, matrix));
        }

        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j]) {
            best = max(best, 1 + dfs(i, j + 1, dp, matrix));
        }

        dp[i][j] = best;
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, dfs(i, j, dp, matrix));
            }
        }

        return answer;
    }
};