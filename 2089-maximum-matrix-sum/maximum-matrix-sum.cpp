class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long res = 0, mn = 1e9, flip = 0;
        for (auto &row : matrix) {
            for (int &x : row) {
                res += abs(x);
                mn = min(mn, (long long)abs(x));
                flip += x < 0;
            }
        }
        return flip & 1 ? res - mn - mn : res;
    }
};