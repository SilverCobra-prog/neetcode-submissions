class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(int i = 0; i < strs.size(); i++) {
            string strCopy = strs[i];
            sort(strCopy.begin(), strCopy.end());
            anagrams[strCopy].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (const auto &pair : anagrams) {
            res.push_back(pair.second);
        }
        return res;
    }
};
