class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = arr.size(), rank = 0, prev = INT_MAX;
        vector<int> res;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            vec.push_back({arr[i], i});
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            if (vec[i].first != prev)
                rank++;
            prev = vec[i].first;
            vec[i].first = rank;
        }
        sort(vec.begin(), vec.end(),
             [](auto a, auto b) { return a.second < b.second; });
        for (auto& [x, y] : vec)
            res.push_back(x);
        return res;
    }
};