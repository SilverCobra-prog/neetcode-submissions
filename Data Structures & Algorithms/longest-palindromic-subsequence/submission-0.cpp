class Solution {
public:
    bool isPalindrome(string& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    int longestPalindromeSubseq(string s) {
        if(s.size() <= 1) return s.size();
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for(int len = 1; len <= s.size(); len++) {
            for(int i = 0; i <= s.size()-len; i++) {
                if(len==1) {
                    dp[i][i] = 1;
                } else if(len==2) {
                    if(s[i] == s[i+1]) dp[i][i+1] = 2;
                    else dp[i][i+1] = 1;
                } else if(s[i] == s[i+len-1]) {
                    dp[i][i+len-1] = max({2+dp[i+1][i+len-2], dp[i+1][i+len-1], dp[i][i+len-2]});
                } else {
                    dp[i][i+len-1] = max(dp[i+1][i+len-1], dp[i][i+len-2]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};