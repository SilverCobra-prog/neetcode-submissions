class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> idx;
        int left = 0;
        int right = 0;
        int ans = 0;

        while(right < s.size()) {
            if(idx[s[right]] != 0) {
                left = max(left, idx[s[right]]);
            }

            idx[s[right]] = right + 1;
            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};