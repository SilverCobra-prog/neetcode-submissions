class NumMatrix {
public:

    vector<vector<int>> prefixSum;
    int n, m;

    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        prefixSum = vector<vector<int>>(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 & j == 0) {
                    prefixSum[i][j] = matrix[i][j];
                } else if (i == 0) {
                    prefixSum[i][j] = prefixSum[i][j-1] + matrix[i][j];
                } else if (j == 0) {
                    prefixSum[i][j] = prefixSum[i-1][j] + matrix[i][j];
                } else {
                    prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefixSum[row2][col2];
        if(row1 > 0) {
            ans -= prefixSum[row1 - 1][col2];
        }
        if(col1 > 0) {
            ans -= prefixSum[row2][col1 - 1];
        }
        if(row1 > 0 && col1 > 0) {
            ans += prefixSum[row1 - 1][col1 - 1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */