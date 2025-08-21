class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int prev = 0;
            for (int j = 0; j < n; j++) {
                prev = mat[i][j] == 1 ? prev + 1 : 0;
                left[i][j] = prev;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                int l = INT_MAX;
                for (int k = i; k >= 0; k--) {
                    l = min(l, left[k][j]);
                    res += l;
                }
            }
        }
        return res;
    }
};