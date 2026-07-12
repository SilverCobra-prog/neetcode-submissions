class Solution {
public:

    unordered_map<int, vector<int>> adj;

    void dfs(int i, vector<bool>& visited) {
        visited[i] = true;
        for(auto j : adj[i]) {
            if(!visited[j]) {
                dfs(j, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        vector<bool> visited(n);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ans++;
                dfs(i, visited);
            }
        }

        return ans;

    }
};
