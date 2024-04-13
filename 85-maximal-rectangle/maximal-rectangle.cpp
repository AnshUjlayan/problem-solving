class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int result = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j] != 0) {
                    mat[i][j] += mat[i][j - 1];
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int height = 1e9, mux = 1;
                for (int i = k; i < m; i++) {
                    height = min(height, mat[i][j]);
                    if (mat[i][j] == 0) {
                        height = 1e9;
                        mux = 0;
                    }
                    result = max(result, height * mux);
                    mux++;
                }
            }
        }
        return result;
    }
};