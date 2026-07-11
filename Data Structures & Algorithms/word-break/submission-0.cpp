class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;

        unordered_map<string, bool> words;
        for(auto word : wordDict) {
            words[word] = true;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && words[s.substr(j, i-j)]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};