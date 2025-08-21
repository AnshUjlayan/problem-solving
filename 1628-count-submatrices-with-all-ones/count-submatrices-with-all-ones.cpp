class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][j]) {
                    mat[i][j] += mat[i][j - 1];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                int l = INT_MAX;
                for (int k = i; k >= 0; k--) {
                    l = min(l, mat[k][j]);
                    res += l;
                }
            }
        }
        return res;
    }
};