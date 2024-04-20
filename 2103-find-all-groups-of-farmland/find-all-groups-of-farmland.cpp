class Solution {
private:
    void dfs(vector<vector<int>>& land, vector<int>& ans, int i, int j) {
        int m = land.size(), n = land[0].size();
        if(i < 0 || j < 0 || i == m || j == n || !land[i][j]) {
            return;
        }
        land[i][j] = 0;
        ans[0] = min(ans[0], i);
        ans[1] = min(ans[1], j);
        ans[2] = max(ans[2], i);
        ans[3] = max(ans[3], j);
        dfs(land, ans, i + 1, j);
        dfs(land, ans, i - 1, j);
        dfs(land, ans, i, j + 1);
        dfs(land, ans, i, j - 1);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>> result;
        int m = land.size(), n = land[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j]) {
                    vector<int> ans {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
                    dfs(land, ans, i, j);
                    result.push_back(ans);
                }
            }
        }
        return result;
    }
};