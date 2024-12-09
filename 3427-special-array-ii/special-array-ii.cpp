class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size(), m = queries.size();
        vector<bool> result(m);
        vector<int> cnt(n, 1);
        for (int i = 1; i < n; i++) {
            cnt[i] = (nums[i] + nums[i - 1]) & 1 ? cnt[i - 1] + 1 : 1;
        }
        for (int i = 0; i < m; i++) {
            result[i] = cnt[queries[i][1]] > queries[i][1] - queries[i][0];
        }
        return result;
    }
};