class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> locs(26, {INT_MAX, INT_MIN});
        for(int i = 0; i < s.size(); i++) {
            locs[s[i] - 'a'].first = min(locs[s[i] - 'a'].first, i);
            locs[s[i] - 'a'].second = max(locs[s[i] - 'a'].second, i);
        }

        sort(locs.begin(), locs.end());

        int start = locs[0].first;
        int end = locs[0].second;
        vector<int> ans;
        for(int i = 1; i < locs.size(); i++) {
            if(locs[i].second == INT_MIN) {
                break;
            }
            
            if(locs[i].first < end) {
                start = min(locs[i].first, start);
                end = max(locs[i].second, end);
            } else {
                ans.push_back(end-start+1);
                start = locs[i].first;
                end = locs[i].second;
            } 
        }
        ans.push_back(end-start+1);
        return ans;
    }
};