class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = score.size();
        vector<string> dard{"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> pairs;
        vector<string> result(n);
        for (int i = 0; i < n; i++) {
            pairs.push_back({score[i], i});
        }
        sort(pairs.rbegin(), pairs.rend());
        for (int i = 0; i < n; i++) {
            auto& [num, idx] = pairs[i];
            if (i < 3) {
                result[idx] = dard[i];
            } else {
                result[idx] = to_string(i + 1);
            }
        }
        return result;
    }
};