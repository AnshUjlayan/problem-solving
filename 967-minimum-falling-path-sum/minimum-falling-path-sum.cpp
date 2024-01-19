class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto getNum = [&](int i, int j) -> int {
            if(j < 0 || j >= n) {
                return 1e5;
            }
            return matrix[i][j];
        };
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] += min({matrix[i - 1][j], getNum(i - 1, j - 1), getNum(i - 1, j + 1)});
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};