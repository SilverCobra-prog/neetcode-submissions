class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> nodes;
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++) {
            nodes[nums[i]] = true;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[nums[i]]) {
                int curr = 1;
                int left = nums[i]-1;
                int right = nums[i]+1;
                while(nodes[left]) {
                    curr++;
                    left--;
                    visited[left] = true;
                }
                while(nodes[right]) {
                    curr++;
                    right++;
                    visited[right] = true;
                }
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};