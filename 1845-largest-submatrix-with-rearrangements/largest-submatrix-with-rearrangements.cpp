class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int j = 0; j < n; j++) {
            int count = 0;
            for(int i = 0; i < m; i++) {
                count = matrix[i][j] == 1 ? count + 1 : 0;
                matrix[i][j] = count;
            }
        }
        for(auto& row : matrix) {
            sort(row.begin(), row.end(), greater<int>());
        }
        int result = 0;
        for(int i = 0; i < m; i++) {
            int height = 1e9;
            for(int j = 0; j < n; j++) {
                height = min(height, matrix[i][j]);
                result = max(result, height * (j + 1));
            }
        }
        return result;
    }
};