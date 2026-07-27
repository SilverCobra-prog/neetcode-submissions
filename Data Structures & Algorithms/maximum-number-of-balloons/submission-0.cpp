class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;
        for(int i = 0; i < text.size(); i++) {
            cnt[text[i]]++;
        }

        int ans = INT_MAX;
        ans = min(cnt['b'], ans);
        ans = min(cnt['a'], ans);
        ans = min(cnt['l']/2, ans);
        ans = min(cnt['o']/2, ans);
        ans = min(cnt['n'], ans);
        return ans;
    }
};