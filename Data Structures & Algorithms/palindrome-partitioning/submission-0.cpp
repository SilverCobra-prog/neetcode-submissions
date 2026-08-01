class Solution {
public:

    vector<vector<string>> ans;

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

    void backtrack(vector<string> &pals, string &curr, string &s, int i) {
        if(i == s.size() && curr=="") {
            ans.push_back(pals);
            return;
        }
        if(i == s.size()) return;
        curr += s[i];
        if(isPalindrome(curr)) {
            pals.push_back(curr);
            string temp = curr;
            curr = "";
            backtrack(pals, curr, s, i+1);
            curr = temp;
            pals.pop_back();
        }
        backtrack(pals, curr, s, i+1);
        curr.pop_back();
    }

    vector<vector<string>> partition(string s) {
        vector<string> pals = {};
        string curr = "";
        backtrack(pals, curr, s, 0);
        return ans;
    }
};
