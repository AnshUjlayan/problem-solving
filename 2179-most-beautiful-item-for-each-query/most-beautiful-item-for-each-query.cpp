class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = items.size(), n = queries.size();
        vector<int> result(n);
        vector<vector<int>> sortedQueries(n);
        for (int i = 0; i < n; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end(), [](auto a, auto b) {
            return a[0] > b[0];
        });
        sort(items.begin(), items.end(), [](auto a, auto b) {
            return a[1] > b[1];
        });
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && items[j][0] > sortedQueries[i][0]) {
                j++;
            }
            sortedQueries[i][0] = j >= m ? 0 : items[j][1];
        }
        for (int i = 0; i < n; i++) {
            result[sortedQueries[i][1]] = sortedQueries[i][0];
        }
        return result;
    }
};