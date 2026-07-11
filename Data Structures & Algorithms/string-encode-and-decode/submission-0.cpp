class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (int i = 0; i < (int)strs.size(); i++) {
            s += strs[i];
            s += "~";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '~') {
                res.push_back(curr);
                curr.clear();
            } else {
                curr += s[i];
            }
        }
        return res;
    }
};
