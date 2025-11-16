class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (auto &q : queries) {
            for (int i = q[0]; i <= q[2]; i++) {
                res[i][q[1]]++;
                if (q[3] < n - 1) res[i][q[3] + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] += res[i][j - 1];
            }
        }
        return res;
    }
};