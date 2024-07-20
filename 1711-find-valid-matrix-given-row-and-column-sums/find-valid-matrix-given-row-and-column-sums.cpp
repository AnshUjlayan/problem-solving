class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mn = min(rowSum[i], colSum[j]);
                result[i][j] = mn;
                rowSum[i] -= mn;
                colSum[j] -= mn;
            }
        }
        return result;
    }
};