class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = grid.size();
        vector<int> result(n, 0), left(n, 0), right(n, 0);
        for(vector<int>& row : grid) {
            int mini = 1e9;
            for(int i = 0; i < n; i++) {
                result[i] = row[i] + min(left[i], right[i]);
                left[i] = mini;
                mini = min(mini, result[i]);
            }
            mini = 1e9;
            for(int i = n - 1; i >= 0; i--) {
                right[i] = mini;
                mini = min(mini, result[i]);
            }
        }
        return *min_element(result.begin(), result.end());
    }
};