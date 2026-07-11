class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> found;
        int left = 0, right = 0, ans = 0;

        while (right < s.size()) {
            if (found[s[right]]) {
                while (s[left] != s[right]) {
                    found[s[left]] = false;
                    left++;
                }
                left++; 
            } else {
                found[s[right]] = true;
                ans = max(ans, right - left + 1);
            }
            right++;
        }
        return ans;
    }
};
