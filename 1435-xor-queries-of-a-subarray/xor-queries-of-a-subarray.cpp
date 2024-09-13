class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = arr.size(), tot = 0;
        vector<int> result, left(n + 1, 0);
        for (int i = 0; i < n; i++) {
            tot ^= arr[i];
            left[i + 1] = tot;
        }
        for (vector<int> &query: queries) {
            result.push_back(left[query[0]] ^ left[query[1] + 1]);
        }
        return result;
    }
};