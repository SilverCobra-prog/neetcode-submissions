class Solution {
public:

    unordered_map<int, vector<int>> neighbors; 

    bool dfs(int v, vector<bool> &visited, int parent) {
        visited[v] = true;

        for (int i : neighbors[v]) {
            if (!visited[i])
            {
                if (dfs(i, visited, v))
                    return true;
            }
            
            else if (i != parent)
                return true;
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1 && edges.empty()) return true;
        int numEdges = edges.size();
        for(int i = 0; i < numEdges; i++) {
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }

        if(n != numEdges+1) return false;

        vector<bool> visited(n);

        if(dfs(0, visited, -1)) return false;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) return false;
        }

        return true;
    }
};