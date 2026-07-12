class Solution {
   public:
    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        visited[x][y] = true;
        if (y > 0 && !visited[x][y - 1] && board[x][y - 1] == 'O') dfs(x, y - 1, visited, board);

        if (y < board[0].size() - 1 && !visited[x][y + 1] && board[x][y + 1] == 'O')
            dfs(x, y + 1, visited, board);

        if (x > 0 && !visited[x - 1][y] && board[x - 1][y] == 'O') dfs(x - 1, y, visited, board);

        if (x < board.size() - 1 && !visited[x + 1][y] && board[x + 1][y] == 'O')
            dfs(x + 1, y, visited, board);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, visited, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, visited, board);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') dfs(0, i, visited, board);
            if (board[n - 1][i] == 'O') dfs(n - 1, i, visited, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
