class Solution {
   public:
    void dfs(int x, int y, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[x][y] = true;
        if (y > 0 && !ocean[x][y - 1] && heights[x][y - 1] >= heights[x][y])
            dfs(x, y - 1, ocean, heights);

        if (y < heights[0].size() - 1 && !ocean[x][y + 1] && heights[x][y + 1] >= heights[x][y])
            dfs(x, y + 1, ocean, heights);

        if (x > 0 && !ocean[x - 1][y] && heights[x - 1][y] >= heights[x][y])
            dfs(x - 1, y, ocean, heights);

        if (x < heights.size() - 1 && !ocean[x + 1][y] && heights[x + 1][y] >= heights[x][y])
            dfs(x + 1, y, ocean, heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m));
        vector<vector<bool>> atlantic(n, vector<bool>(m));

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, m - 1, atlantic, heights);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, pacific, heights);
            dfs(n - 1, j, atlantic, heights);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;

    }
};
