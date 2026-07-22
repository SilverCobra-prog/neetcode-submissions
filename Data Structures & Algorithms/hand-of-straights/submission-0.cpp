class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());
        if(n % groupSize != 0) return false;
        int numGroups = n / groupSize;
        vector<vector<int>> groups(numGroups);
        int left = 0;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            if(i != 0 && hand[i] == hand[i-1]) {
                curr++;
                if(curr == numGroups) return false;
                groups[curr].push_back(hand[i]);
                if(groups[curr].size() == groupSize) left++;
            } else {
                curr = left;
                int currSize = groups[curr].size();
                if(currSize > 0 && groups[curr][currSize-1] != hand[i]-1)
                    return false;
                groups[curr].push_back(hand[i]);
                if(groups[curr].size() == groupSize) left++;
            }
        }
        return true;
    }
};