class Solution {
   public:
    unordered_map<int, vector<int>> graph;

    bool dfs(int i, int parent, vector<bool>& visited) {
        visited[i] = true;

        for (auto j : graph[i]) {
            if (!visited[j]) {
                if (!dfs(j, i, visited)) return false;
            } else if (j != parent) {
                return false;
            }
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        for (int i = 0; i < n; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);

            vector<bool> visited(n + 1, false);

            if (!dfs(edges[i][0], -1, visited)) {
                return edges[i];
            }
        }

        return {};
    }
};